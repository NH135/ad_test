//
//  BaiduMobAdCustomVideoView.h
//  BaiduMobAdSDK
//
//  Created by Yang,Dingjia on 2018/11/13.
//  Copyright © 2018 Baidu Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BaiduMobAdCommonConfig.h"
#import <AVFoundation/AVFoundation.h>

@class BaiduMobAdVideoView;
@protocol BaiduMobAdVideoViewDelegate <NSObject>
@optional

/**
 视频准备开始播放
 
 @param videoView self
 */
- (void)fullscreenVideoAdDidStartPlaying:(BaiduMobAdVideoView *)videoView;

/**
 视频暂停播放
 
 @param videoView self
 */
- (void)fullscreenVideoAdDidPause:(BaiduMobAdVideoView *)videoView;

/**
 视频重播
 
 @param videoView self
 */
- (void)fullscreenVideoAdDidReplay:(BaiduMobAdVideoView *)videoView;

/**
 视频播放完成

 @param videoView self
 */
- (void)fullscreenVideoAdDidComplete:(BaiduMobAdVideoView *)videoView;

/**
 视频播放失败

 @param videoView self
 */
- (void)fullscreenVideoAdDidFailed:(BaiduMobAdVideoView *)videoView;

/**
 视频发生点击
 
 @param videoView self
 */
- (void)fullscreenVideoAdDidClick:(BaiduMobAdVideoView *)videoView;

@end

@interface BaiduMobAdVideoView : UIView

@property (nonatomic, weak) id <BaiduMobAdVideoViewDelegate> delegate;

/**
 * 广告素材type
 */
@property (nonatomic, assign) BaiduMobMaterialType materialType;

/**
 初始化方法

 @param frame videoView尺寸
 @param object BaiduMobAdNativeAdObject
 @return BaiduMobAdVideoView
 */
- (instancetype)initWithFrame:(CGRect)frame andObject:(id)object;

/**
 设置AVAudioSessionCategory，play之前调用，默认：AVAudioSessionCategoryAmbient
 */
- (void)setAudioSessionCategory:(AVAudioSessionCategory)category;

/**
 开始播放
 */
- (void)play;

/**
 重新播放
 */
- (void)replay;

/**
 暂停播放
 */
- (void)pause;

/**
 销毁播放器
 */
- (void)stop;

/**
 设置静音

 @param mute YES静音   NO非静音
 */
- (void)setVideoMute:(BOOL)mute;

/**
 是否播放中

 @return isPlaying
 */
- (BOOL)isPlaying;

/**
 当前播放时间

 @return 当前播放时间
 */
- (NSTimeInterval)currentTime;

/**
 视频总时长

 @return 视频总时长
 */
- (NSTimeInterval)duration;

#pragma mark - 计费相关视频事件 重要！

/**
 视频点击事件 点击计费接口
 */
- (void)handleClick;

/**
 视频曝光事件 已废弃，无需开发者发送
 */
- (void)trackImpression BaiduMobAdDEPRECATED_MSG("已废弃，无需开发者发送");

@end
