//
//  STPCheckoutWebViewAdapter.h
//  Stripe
//
//  Created by Jack Flintermann on 1/7/15.
//  Copyright (c) 2015 Stripe, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#define STP_VIEW_CLASS UIView
#else
#define STP_VIEW_CLASS NSView
#endif

static NSString *const checkoutOptionsGlobal = @"StripeCheckoutOptions";
static NSString *const checkoutRedirectPrefix = @"/-/";
static NSString *const checkoutURLPathIdentifier = @"NativeCheckoutEvent";
static NSString *const checkoutUserAgent = @"Stripe";

static NSString *const checkoutHost = @"localhost:5394";
// static NSString *const checkoutHost = @"checkout.stripe.com";
static NSString *const checkoutURLString = @"http://localhost:5394/v3/ios/index.html";
// static NSString *const checkoutURLString = @"https://checkout.stripe.com/v3/ios/index.html";

@protocol STPCheckoutDelegate;
@protocol STPCheckoutWebViewAdapter<NSObject>
@property (nonatomic, weak) id<STPCheckoutDelegate> delegate;
@property (nonatomic, readonly) STP_VIEW_CLASS *webView;
- (void)loadRequest:(NSURLRequest *)request;
- (void)evaluateJavaScript:(NSString *)js;
- (void)cleanup;
@end
