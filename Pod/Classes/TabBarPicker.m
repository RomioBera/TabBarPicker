//
//  TabBarPicker.m
//  Pods
//
//  Created by Giuseppe Nucifora on 15/07/15.
//
//

#import "TabBarPicker.h"
#import <PureLayout/PureLayout.h>
#import "TabBarPickerSubItemsView.h"

@interface TabBarPicker() <TabBarItemDelegate>

@property (nonatomic) UIDeviceOrientation orientation;

@end

@implementation TabBarPicker

- (instancetype) initWithTabBarItems:(NSArray *)items forPosition:(TabBarPickerPosition)position {
    
    return [self initWithTabBarItems:items withTabBarSize:CGSizeZero forPosition:position andNSLayoutRelation:NSLayoutRelationEqual];
    
}

- (instancetype) initWithTabBarItems:(NSArray *)items forPosition:(TabBarPickerPosition)position andNSLayoutRelation:(NSLayoutRelation)relation {
    
    return [self initWithTabBarItems:items withTabBarSize:CGSizeZero forPosition:position andNSLayoutRelation:relation];
    
}

- (instancetype) initWithTabBarItems:(NSArray*) items withTabBarSize:(CGSize) size forPosition:(TabBarPickerPosition) position andNSLayoutRelation:(NSLayoutRelation)relation {
    
    self = [self initForAutoLayout];
    if (self) {
        _itemSpacing = 10;
        _paddingLeft = 0;
        _paddingRight = 0;
        _paddingTop = 0;
        _paddingBottom = 0;
        _layoutRelation = relation;
        
        _position = position;
        
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        
        [[NSNotificationCenter defaultCenter] addObserver: self selector:   @selector(deviceOrientationDidChange:) name: UIDeviceOrientationDidChangeNotification object: nil];
        
        NSAssert(items, @"TabBar Items array cannot be nil!");
        
        if (CGSizeEqualToSize(size, CGSizeZero)) {
            _tabBarSize = CGSizeMake([[UIScreen mainScreen] bounds].size.width, 44);
        }
        
        _tabBarItems = [[NSMutableArray alloc] init];
        
        for (NSObject *item in items) {
            [self addItem:item];
        }
    }
    
    [self setNeedsUpdateConstraints];
    
    return self;
}

- (void) layoutSubviews {
    
    switch (_position) {
        case TabBarPickerPositionLeft:{
            [self autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20];
            [self autoPinEdgeToSuperviewEdge:ALEdgeLeft withInset:0];
            [self autoSetDimension:ALDimensionWidth toSize:44];
            [self autoMatchDimension:ALDimensionHeight toDimension:ALDimensionHeight ofView:self.superview withOffset:0 relation:_layoutRelation];
            [self autoAlignAxisToSuperviewMarginAxis:ALAxisHorizontal];
            
            [_tabBarItems autoSetViewsDimension:ALDimensionWidth toSize:44.0];
            
            [_tabBarItems autoDistributeViewsAlongAxis:ALAxisVertical alignedTo:ALAttributeVertical withFixedSpacing:_itemSpacing insetSpacing:YES matchedSizes:YES];
            
            [[_tabBarItems firstObject] autoAlignAxisToSuperviewAxis:ALAxisVertical];
        }
            break;
        case TabBarPickerPositionRight:{
            [self autoPinEdgeToSuperviewEdge:ALEdgeTop withInset:20];
            [self autoPinEdgeToSuperviewEdge:ALEdgeRight withInset:0];
            [self autoSetDimension:ALDimensionWidth toSize:44];
            [self autoMatchDimension:ALDimensionHeight toDimension:ALDimensionHeight ofView:self.superview withOffset:0 relation:_layoutRelation];
            [self autoAlignAxisToSuperviewMarginAxis:ALAxisHorizontal];
            
            [_tabBarItems autoSetViewsDimension:ALDimensionWidth toSize:44.0];
            
            [_tabBarItems autoDistributeViewsAlongAxis:ALAxisVertical alignedTo:ALAttributeVertical withFixedSpacing:_itemSpacing insetSpacing:YES matchedSizes:YES];
            
            [[_tabBarItems firstObject] autoAlignAxisToSuperviewAxis:ALAxisVertical];
        }
            break;
        case TabBarPickerPositionTop:{
            [self autoPinEdgeToSuperviewMargin:ALEdgeTop];
            [self autoSetDimension:ALDimensionHeight toSize:44];
            [self autoMatchDimension:ALDimensionWidth toDimension:ALDimensionWidth ofView:self.superview withOffset:0 relation:_layoutRelation];
            [self autoAlignAxisToSuperviewMarginAxis:ALAxisVertical];
            
            [_tabBarItems autoSetViewsDimension:ALDimensionHeight toSize:44.0];
            
            [_tabBarItems autoDistributeViewsAlongAxis:ALAxisHorizontal alignedTo:ALAttributeHorizontal withFixedSpacing:_itemSpacing insetSpacing:YES matchedSizes:YES];
            
            [[_tabBarItems firstObject] autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
        }
            break;
        case TabBarPickerPositionBottom:
        default:{
            [self autoPinEdgeToSuperviewMargin:ALEdgeBottom];
            [self autoSetDimension:ALDimensionHeight toSize:44];
            [self autoMatchDimension:ALDimensionWidth toDimension:ALDimensionWidth ofView:self.superview withOffset:0 relation:_layoutRelation];
            [self autoAlignAxisToSuperviewMarginAxis:ALAxisVertical];
            
            [_tabBarItems autoSetViewsDimension:ALDimensionHeight toSize:44.0];
            
            [_tabBarItems autoDistributeViewsAlongAxis:ALAxisHorizontal alignedTo:ALAttributeHorizontal withFixedSpacing:0 insetSpacing:YES matchedSizes:YES];
            
            [[_tabBarItems firstObject] autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
        }
            break;
    }
    
    [self updateConstraints];
}

- (void) setPosition:(TabBarPickerPosition)position {
    _position = position;
    
    if (self.superview) {
        [self removeConstraints:self.constraints];
        
        for (TabBarItem *item in _tabBarItems) {
            [item removeConstraints:item.constraints];
        }
        
        [self layoutSubviews];
    }
}

- (void)deviceOrientationDidChange:(NSNotification *)notification {
    //Obtain current device orientation
    _orientation = [[UIDevice currentDevice] orientation];
    
    [self layoutSubviews];
}

- (void) addItem:(TabBarItem*) item {
    if (item && [item isKindOfClass:[TabBarItem class]]) {
        
        NSLog(@"%@",self.constraints);
        
        [_tabBarItems addObject:item];
        [item setBackgroundColor:[UIColor lightGrayColor]];
        [item setDelegate:self];
        [self addSubview:item];
        
        
        if (self.superview) {
            
            [self removeConstraints:self.constraints];
            for (TabBarItem *item in _tabBarItems) {
                [item removeConstraints:item.constraints];
            }
            
            [self layoutSubviews];
        }
    }
}

- (void) layoutSubviewsPortrait {
    
}

- (void) layoutSubviewsLandScape {
    
}

@end
