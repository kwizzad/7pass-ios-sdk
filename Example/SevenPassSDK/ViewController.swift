//
//  ViewController.swift
//  SevenPass
//
//  Created by Jan Votava on 12/21/2015.
//  Copyright (c) 2015 Jan Votava. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITabBarDelegate {
    @IBOutlet weak var loginContentView: UIView!
    @IBOutlet weak var tabBarView: UITabBar!
    @IBOutlet weak var refreshButton: UIBarButtonItem!
    @IBOutlet weak var logoutButton: UIBarButtonItem!
    @IBOutlet weak var statusbar: UIBarButtonItem!
    
    fileprivate var activeViewController: UIViewController? {
        didSet {
            removeInactiveViewController(oldValue)
            updateActiveViewController()
        }
    }
    
    @IBAction func refresh(_ sender: AnyObject) {
        if let refreshTokenString = SsoManager.sharedInstance.tokenSet?.refreshToken?.token {
            SsoManager.sharedInstance.sso.authorize(refreshToken: refreshTokenString,
                success: { tokenSet in
                    SsoManager.sharedInstance.updateTokenSet(tokenSet)
                },
                failure: errorHandler
            )
        }
    }

    @IBAction func logout(_ sender: AnyObject) {
        SsoManager.sharedInstance.updateTokenSet(nil)
        SsoManager.sharedInstance.sso.destroyWebviewSession(failure: errorHandler)

        updateStatusbar()
    }

    fileprivate func removeInactiveViewController(_ inactiveViewController: UIViewController?) {
        if let inActiveVC = inactiveViewController {
            // call before removing child view controller's view from hierarchy
            inActiveVC.willMove(toParentViewController: nil)
            
            inActiveVC.view.removeFromSuperview()
            
            // call after removing child view controller's view from hierarchy
            inActiveVC.removeFromParentViewController()
        }
    }
    
    fileprivate func updateActiveViewController() {
        if let activeVC = activeViewController {
            // call before adding child view controller's view as subview
            addChildViewController(activeVC)
            
            activeVC.view.frame = loginContentView.bounds
            loginContentView.addSubview(activeVC.view)
            
            // call before adding child view controller's view as subview
            activeVC.didMove(toParentViewController: self)
        }
    }
    
    func tabBar(_ tabBar: UITabBar, didSelect item: UITabBarItem) {
        activeViewController = loginViews[item.tag]
    }
    
    var loginViews: [UIViewController] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let webViewController = storyboard!.instantiateViewController(withIdentifier: "webView")
        let passwordLoginController = storyboard!.instantiateViewController(withIdentifier: "passwordLogin")
        let registrationController = storyboard!.instantiateViewController(withIdentifier: "registrationView")

        loginViews = [webViewController, passwordLoginController, registrationController]

        // Select first tab
        activeViewController = webViewController
        tabBarView.selectedItem = tabBarView.items![0]

        updateStatusbar()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func updateStatusbar() {
        if let tokenSet = SsoManager.sharedInstance.tokenSet {
            logoutButton.isEnabled = true
            refreshButton.isEnabled = true
            statusbar.title = tokenSet.email
        } else {
            logoutButton.isEnabled = false
            refreshButton.isEnabled = false
            statusbar.title = nil
        }
    }
}

