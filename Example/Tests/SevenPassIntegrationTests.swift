import XCTest
import SevenPassSDK

class SevenPassIntegration: XCTestCase {

    // Use same instance of SevenPass for all integration tests (should reflect real-world usage).
    fileprivate lazy var sevenPass: SevenPass = {
        let configuration = SevenPassConfiguration(
            consumerKey: "56a0982fcd8fb606d000b233",
            consumerSecret: "2e7b77f99be28d80a60e9a2d2c664835ef2e02c05bf929f60450c87c15a59992",
            callbackUri: "oauthtest://oauth-callback",
            environment: "qa"
        )

        return SevenPass(configuration: configuration)
    }()

    fileprivate let testUsername = "prosiebendigital+7@gmail.com"
    fileprivate let testPassword = "Kunf_tiger7"

    override func setUp() {
        super.setUp()
    }

    override func tearDown() {
        super.tearDown()
    }

    // MARK: - Tokens

    func testPasswordLogin() {
        let expectation = self.expectation(description: "Password Login")

        sevenPass.authorize(
            login: testUsername,
            password: testPassword,
            scopes: ["openid", "profile", "email"],
            success: { tokenSet in
                XCTAssertNotNil(tokenSet.accessToken?.token)
                XCTAssertFalse(tokenSet.accessToken!.isExpired())
                XCTAssertNotNil(tokenSet.email)
                expectation.fulfill()
            },
            failure: { error in
                XCTFail(error.localizedDescription)
                expectation.fulfill()
            }
        )

        waitForExpectations(timeout: 10) { _ in }
    }

    func testRefreshToken() {
        let expectation = self.expectation(description: "Refresh Token")

        authorize { authTokenSet in
            guard let refreshToken = authTokenSet.refreshToken?.token else {
                XCTFail("Refresh token not set")
                return
            }

            self.sevenPass.authorize(refreshToken: refreshToken,
                success: { tokenSet in
                    XCTAssertNotNil(tokenSet.accessToken?.token)
                    XCTAssertNotNil(tokenSet.refreshToken?.token)
                    expectation.fulfill()
                },
                failure: { error in
                    XCTFail(error.localizedDescription)
                    expectation.fulfill()
                }
            )
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    // MARK: - Account

    func testAccountDetails() {
        let expectation = self.expectation(description: "Get Account Details")

        authorize { authTokenSet in
            let accountClient = self.sevenPass.accountClient(authTokenSet)

            accountClient.get("me",
                success: { json, response in
                    guard let
                        status = json["status"] as? String,
                        let data = json["data"] as? [String: AnyObject],
                        let email = data["email"] as? String,
                        let _ = data["email_verified"] as? String else {
                            XCTFail("JSON response invalid.")
                            return
                    }

                    XCTAssertEqual(status, "success")
                    XCTAssertEqual(email, self.testUsername)
                    expectation.fulfill()
                },
                failure: { error in
                    XCTFail(error.localizedDescription)
                    expectation.fulfill()
                }
            )
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    // MARK: - Email

    func testEmailIsTaken() {
        let expectation = self.expectation(description: "Email is taken")

        fetchEmailAvailability(testUsername) { isAvailable in
            XCTAssertFalse(isAvailable)
            expectation.fulfill()
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    func testEmailIsAvailable() {
        let expectation = self.expectation(description: "Email is available")

        fetchEmailAvailability("prosiebendigital+42@gmail.com") { isAvailable in
            XCTAssertTrue(isAvailable)
            expectation.fulfill()
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    // MARK: - Passwords

    func testPasswordIsValid() {
        let expectation = self.expectation(description: "Password is valid")

        fetchPasswordValidity("kunftiger7") { isValid in
            XCTAssertTrue(isValid)
            expectation.fulfill()
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    func testPasswordIsInvalid() {
        let expectation = self.expectation(description: "Password is invalid")

        fetchPasswordValidity("12345") { isValid in
            XCTAssertFalse(isValid)
            expectation.fulfill()
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    // MARK: - Registration

    func testRegistration() {
        let expectation = self.expectation(description: "Register new user")

        let randAccountSuffix = 2000 + arc4random_uniform(UInt32.max)

        fetchCredentials { deviceClient in
            deviceClient.post("registration",
                parameters: [
                    "email": "prosiebendigital+\(randAccountSuffix)@gmail.com",
                    "password": self.testPassword,
                    "flags": [
                        "client": [
                            "id": self.sevenPass.configuration.consumerKey,
                            "agb": true,
                            "dsb": true,
                            "implicit": true
                        ]
                    ]
                ],
                success: { json, response in
                    if let
                        data = json["data"] as? [String: AnyObject],
                        let registered = data["registered"] as? Bool {
                            XCTAssertTrue(registered)
                    } else {
                        XCTFail("Not registered.")
                    }
                    expectation.fulfill()
                },
                failure: { error in
                    XCTFail(error.localizedDescription)
                    expectation.fulfill()
                }
            )
        }

        waitForExpectations(timeout: 10) { _ in }
    }

    // MARK: - Helper methods

    fileprivate func authorize(_ completion: @escaping (SevenPassTokenSet) -> Void) {
        sevenPass.authorize(
            login: testUsername,
            password: testPassword,
            scopes: ["openid", "profile", "email"],
            success: { tokenSet in
                completion(tokenSet)
            },
            failure: { error in
                XCTFail(error.localizedDescription)
            }
        )
    }

    fileprivate func fetchCredentials(_ completion: @escaping (SevenPassClient) -> Void) {
        sevenPass.authorize(
            parameters: [
                "grant_type": "client_credentials",
            ],
            success: { tokenSet in
                completion(self.sevenPass.credentialsClient(tokenSet))
            },
            failure: { error in
                XCTFail(error.localizedDescription)
            }
        )
    }

    fileprivate func fetchEmailAvailability(_ email: String, completion: @escaping (Bool) -> Void) {
        fetchCredentials { deviceClient in
            deviceClient.post("checkMail",
                parameters: [
                    "email": email,
                    "flags": [
                        "client_id": self.sevenPass.configuration.consumerKey
                    ]
                ],
                success: { json, response in
                    if let
                        data = json["data"] as? [String: AnyObject],
                        let available = data["available"] as? Bool {
                            completion(available)
                    } else {
                        XCTFail("Invalid json.")
                    }
                },
                failure: { error in
                    XCTFail(error.localizedDescription)
                }
            )
        }
    }

    fileprivate func fetchPasswordValidity(_ password: String, completion: @escaping (Bool) -> Void) {
        fetchCredentials { deviceClient in
            deviceClient.post("checkPassword",
                parameters: [
                    "password": password
                ],
                success: { json, response in
                    if let
                        data = json["data"] as? [String: AnyObject],
                        let valid = data["accepted"] as? Bool {
                            completion(valid)
                    } else {
                        XCTFail("Invalid json.")
                    }
                },
                failure: { error in
                    XCTFail(error.localizedDescription)
                }
            )
        }
    }

}
