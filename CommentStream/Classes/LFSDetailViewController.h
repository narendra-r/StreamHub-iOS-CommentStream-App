//
//  LFSDetailViewController.h
//  CommentStream
//
//  Created by Eugene Scherba on 9/13/13.
//  Copyright (c) 2013 Livefyre. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <StreamHub-iOS-SDK/LFSConstants.h>

#import "LFSAuthorProfile.h"
#import "LFSContent.h"
#import "LFSUser.h"

#import "LFSDetailView.h"
#import "LFSPostViewController.h"

#import "LFSAttributedLabelDelegate.h"
#import "LFSContentActions.h"

@protocol LFSDetailViewDelegate;
@protocol LFSDetailViewControllerDelegate;

@interface LFSDetailViewController : UIViewController <LFSDetailViewDelegate, LFSPostViewControllerDelegate, LFSContentActionsDelegate>

@property (nonatomic, assign) BOOL hideStatusBar;

@property (nonatomic, copy) NSDictionary *collection;
@property (nonatomic, copy) NSString *collectionId;
@property (nonatomic, strong) UIImage *avatarImage;
@property (nonatomic, strong) LFSContent *contentItem;

@property (nonatomic, strong) LFSUser *user;

@property (nonatomic, strong) LFSAttributedLabelDelegate *attributedLabelDelegate;

@property (nonatomic, weak) id<LFSDetailViewControllerDelegate> delegate;

@end

@protocol LFSDetailViewControllerDelegate <NSObject>

-(void)didPostContentWithOperation:(NSOperation*)operation response:(id)responseObject;
-(void)deleteContent:(LFSContent*)content;
-(void)flagContent:(LFSContent*)content withFlag:(LFSContentFlag)flag;

@end
