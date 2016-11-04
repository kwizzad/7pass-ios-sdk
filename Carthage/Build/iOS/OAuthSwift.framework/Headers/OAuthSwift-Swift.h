// Generated by Apple Swift version 3.0.1 (swiftlang-800.0.58.6 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import Foundation;
@import ObjectiveC;
@import UIKit;
@import SafariServices;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

@interface NSError (SWIFT_EXTENSION(OAuthSwift))
/**
  Checks the headers contained in the userInfo whether this error was caused by an
  expired/invalid access token.
  Criteria for invalid token error: WWW-Authenticate header contains a field “error” with
  value “invalid_token”.
  Also implements a special handling for the Facebook API, which indicates invalid tokens in a
  different manner. See https://developers.facebook.com/docs/graph-api/using-graph-api#errors
*/
@property (nonatomic, readonly) BOOL isExpiredToken;
@end


SWIFT_PROTOCOL("_TtP10OAuthSwift23OAuthSwiftRequestHandle_")
@protocol OAuthSwiftRequestHandle
- (void)cancel;
@end

@class OAuthSwiftClient;
@protocol OAuthSwiftURLHandlerType;
@class NSNotificationCenter;
@class NSOperationQueue;

SWIFT_CLASS("_TtC10OAuthSwift10OAuthSwift")
@interface OAuthSwift : NSObject <OAuthSwiftRequestHandle>
@property (nonatomic, strong) OAuthSwiftClient * _Nonnull client;
@property (nonatomic, strong) id <OAuthSwiftURLHandlerType> _Nonnull authorizeURLHandler;
+ (void)handleWithUrl:(NSURL * _Nonnull)url;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) NSNotificationCenter * _Nonnull notificationCenter;)
+ (NSNotificationCenter * _Nonnull)notificationCenter;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) NSOperationQueue * _Nonnull notificationQueue;)
+ (NSOperationQueue * _Nonnull)notificationQueue;
- (void)removeCallbackNotificationObserver;
- (void)cancel;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC10OAuthSwift11OAuth1Swift")
@interface OAuth1Swift : OAuthSwift
@property (nonatomic) BOOL allowMissingOAuthVerifier;
- (nonnull instancetype)initWithConsumerKey:(NSString * _Nonnull)consumerKey consumerSecret:(NSString * _Nonnull)consumerSecret requestTokenUrl:(NSString * _Nonnull)requestTokenUrl authorizeUrl:(NSString * _Nonnull)authorizeUrl accessTokenUrl:(NSString * _Nonnull)accessTokenUrl OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithParameters:(NSDictionary<NSString *, NSString *> * _Nonnull)parameters;
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> * _Nonnull parameters;
@end


SWIFT_CLASS("_TtC10OAuthSwift11OAuth2Swift")
@interface OAuth2Swift : OAuthSwift
@property (nonatomic) BOOL accessTokenBasicAuthentification;
@property (nonatomic) BOOL allowMissingStateCheck;
- (nonnull instancetype)initWithConsumerKey:(NSString * _Nonnull)consumerKey consumerSecret:(NSString * _Nonnull)consumerSecret authorizeUrl:(NSString * _Nonnull)authorizeUrl accessTokenUrl:(NSString * _Nonnull)accessTokenUrl responseType:(NSString * _Nonnull)responseType;
- (nonnull instancetype)initWithConsumerKey:(NSString * _Nonnull)consumerKey consumerSecret:(NSString * _Nonnull)consumerSecret authorizeUrl:(NSString * _Nonnull)authorizeUrl accessTokenUrl:(NSString * _Nonnull)accessTokenUrl responseType:(NSString * _Nonnull)responseType contentType:(NSString * _Nonnull)contentType;
- (nonnull instancetype)initWithConsumerKey:(NSString * _Nonnull)consumerKey consumerSecret:(NSString * _Nonnull)consumerSecret authorizeUrl:(NSString * _Nonnull)authorizeUrl responseType:(NSString * _Nonnull)responseType OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithParameters:(NSDictionary<NSString *, NSString *> * _Nonnull)parameters;
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> * _Nonnull parameters;
@end



@interface OAuthSwift (SWIFT_EXTENSION(OAuthSwift))
@end


@interface OAuthSwift (SWIFT_EXTENSION(OAuthSwift))
@end

@class OAuthSwiftCredential;
enum ParamsLocation : NSInteger;
@class OAuthSwiftHTTPRequest;

SWIFT_CLASS("_TtC10OAuthSwift16OAuthSwiftClient")
@interface OAuthSwiftClient : NSObject
@property (nonatomic, readonly, strong) OAuthSwiftCredential * _Nonnull credential;
@property (nonatomic) enum ParamsLocation paramsLocation;
- (nonnull instancetype)initWithCredential:(OAuthSwiftCredential * _Nonnull)credential OBJC_DESIGNATED_INITIALIZER;
- (OAuthSwiftHTTPRequest * _Nonnull)makeRequest:(NSURLRequest * _Nonnull)request;
- (NSData * _Nonnull)multiPartBodyFrom:(NSDictionary<NSString *, id> * _Nonnull)inputParameters boundary:(NSString * _Nonnull)boundary;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class NSCoder;

SWIFT_CLASS("_TtC10OAuthSwift20OAuthSwiftCredential")
@interface OAuthSwiftCredential : NSObject <NSCoding>
@property (nonatomic, copy) NSString * _Nonnull oauthToken;
@property (nonatomic, copy) NSString * _Nonnull oauthRefreshToken;
@property (nonatomic, copy) NSString * _Nonnull oauthTokenSecret;
@property (nonatomic, copy) NSDate * _Nullable oauthTokenExpiresAt;
@property (nonatomic, readonly, copy) NSString * _Nonnull oauthVerifier;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
- (nonnull instancetype)initWithConsumerKey:(NSString * _Nonnull)consumerKey consumerSecret:(NSString * _Nonnull)consumerSecret OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)decoder;
- (void)encodeWithCoder:(NSCoder * _Nonnull)coder;
+ (NSString * _Nonnull)generateNonce;
- (NSDictionary<NSString *, id> * _Nonnull)authorizationParameters:(NSData * _Nullable)body timestamp:(NSString * _Nonnull)timestamp nonce:(NSString * _Nonnull)nonce;
- (BOOL)isTokenExpired;
@end


SWIFT_CLASS("_TtC10OAuthSwift21OAuthSwiftHTTPRequest")
@interface OAuthSwiftHTTPRequest : NSObject <NSURLSessionDelegate, OAuthSwiftRequestHandle>
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) void (^ _Nonnull executionContext)(void (^ _Nonnull)(void));)
+ (void (^ _Nonnull)(void (^ _Nonnull)(void)))executionContext;
+ (void)setExecutionContext:(void (^ _Nonnull)(void (^ _Nonnull)(void)))value;
- (void)cancel;
- (NSURLRequest * _Nullable)makeRequestAndReturnError:(NSError * _Nullable * _Nullable)error;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

typedef SWIFT_ENUM(NSInteger, ParamsLocation) {
  ParamsLocationAuthorizationHeader = 0,
  ParamsLocationRequestURIQuery = 1,
};


@interface OAuthSwiftHTTPRequest (SWIFT_EXTENSION(OAuthSwift))
@end


@interface OAuthSwiftHTTPRequest (SWIFT_EXTENSION(OAuthSwift))
@end



SWIFT_PROTOCOL("_TtP10OAuthSwift24OAuthSwiftURLHandlerType_")
@protocol OAuthSwiftURLHandlerType
- (void)handle:(NSURL * _Nonnull)url;
@end

@class NSBundle;

SWIFT_CLASS("_TtC10OAuthSwift22OAuthWebViewController")
@interface OAuthWebViewController : UIViewController <OAuthSwiftURLHandlerType>
@property (nonatomic) BOOL useTopViewControlerInsteadOfNavigation;
@property (nonatomic, readonly, strong) UIViewController * _Nullable topViewController;
- (void)handle:(NSURL * _Nonnull)url;
- (void)doHandle:(NSURL * _Nonnull)url;
- (void)dismissWebViewController;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class SFSafariViewController;
@class UIActivity;

SWIFT_CLASS("_TtC10OAuthSwift16SafariURLHandler")
@interface SafariURLHandler : NSObject <OAuthSwiftURLHandlerType, SFSafariViewControllerDelegate>
@property (nonatomic, readonly, strong) OAuthSwift * _Nonnull oauthSwift;
@property (nonatomic, copy) void (^ _Nonnull present)(SFSafariViewController * _Nonnull, SafariURLHandler * _Nonnull);
@property (nonatomic, copy) void (^ _Nonnull dismiss)(SFSafariViewController * _Nonnull, SafariURLHandler * _Nonnull);
@property (nonatomic, copy) SFSafariViewController * _Nonnull (^ _Nonnull factory)(NSURL * _Nonnull);
@property (nonatomic, strong) id <SFSafariViewControllerDelegate> _Nullable delegate;
@property (nonatomic) BOOL animated;
@property (nonatomic, copy) void (^ _Nullable presentCompletion)(void);
@property (nonatomic, copy) void (^ _Nullable dismissCompletion)(void);
- (nonnull instancetype)initWithViewController:(UIViewController * _Nonnull)viewController oauthSwift:(OAuthSwift * _Nonnull)oauthSwift OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithPresent:(void (^ _Nonnull)(SFSafariViewController * _Nonnull, SafariURLHandler * _Nonnull))present dismiss:(void (^ _Nonnull)(SFSafariViewController * _Nonnull, SafariURLHandler * _Nonnull))dismiss oauthSwift:(OAuthSwift * _Nonnull)oauthSwift OBJC_DESIGNATED_INITIALIZER;
- (void)handle:(NSURL * _Nonnull)url;
- (void)clearObservers;
- (void)clearLocalObservers;
- (NSArray<UIActivity *> * _Nonnull)safariViewController:(SFSafariViewController * _Nonnull)controller activityItemsForURL:(NSURL * _Nonnull)URL title:(NSString * _Nullable)title;
- (void)safariViewControllerDidFinish:(SFSafariViewController * _Nonnull)controller;
- (void)safariViewController:(SFSafariViewController * _Nonnull)controller didCompleteInitialLoad:(BOOL)didLoadSuccessfully;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


@interface UIApplication (SWIFT_EXTENSION(OAuthSwift))
@end


@interface UIViewController (SWIFT_EXTENSION(OAuthSwift))
@end

#pragma clang diagnostic pop
