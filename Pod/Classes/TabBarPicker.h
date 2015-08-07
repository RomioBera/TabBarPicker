//
//  TabBarPicker.h
//  Pods
//
//  Created by Giuseppe Nucifora on 15/07/15.
//
//

#import <UIKit/UIKit.h>
#import "TabbarItem.h"
#import "TabBarSubItem.h"

typedef NS_ENUM(NSInteger, TabBarPickerPosition) {
    // Informational
    TabBarPickerPositionLeft,
    TabBarPickerPositionRight,
    TabBarPickerPositionBottom,
    TabBarPickerPositionTop
    
};

@interface TabBarPicker : UIView

@property (nonatomic, strong, readonly) NSMutableArray *tabBarItems;
@property (nonatomic, readonly) CGSize tabBarSize;
@property (nonatomic, readonly) TabBarPickerPosition position;
@property (nonatomic, readonly) NSLayoutRelation layoutRelation;
@property (nonatomic) CGFloat itemSpacing;
@property (nonatomic, readonly) NSUInteger subItemPerRow;
@property (nonatomic, readonly) CGFloat subItemHeight;
@property (nonatomic) BOOL dimWhenShow;
@property (nonatomic, strong) UIColor * dimColor;

/**
 *  Init TabBarPicker with items. When is selected an item the picher show down subitems.
 *  By default when one of more subItems are selected the selected item become selected.
 *  By default the tabBar size is max screen width and 100px height
 *  The picker size is dinamically based the max subitems of items.
 *  For this method is used NSLayoutRelationEqual as NSLayoutRelation configuration.
 *
 *  @param items Represents tab bar items. That array cannot be nil.
 *
 *  @param position Represents the posizion in the Screen:
 *                      - TabBarPickerPositionLeft : Is positioned in vertical on left of the screen and shows the picker at its right
 *                      - TabBarPickerPositionRight : Is positioned in vertical on right of the screen and shows the picker at its left
 *                      - TabBarPickerPositionBottom : Is positioned in horizontal on bottom of the screen and shows the picker at its top
 *                      - TabBarPickerPositionTop : Is positioned in horizontal on top of the screen and shows the picker at its bottom
 *
 *  @return raturn instance of TabBarPicker object.
 */
- (instancetype) initWithTabBarItems:(NSArray *) items forPosition:(TabBarPickerPosition) position;

/**
 *  Init TabBarPicker with items. When is selected an item the picher show down subitems.
 *  By default when one of more subItems are selected the selected item become selected.
 *  By default the tabBar size is max screen width and 100px height
 *  The picker size is dinamically based the max subitems of items.
 *
 *  @param items Represents tab bar items. That array cannot be nil.
 *
 *  @param position Represents the posizion in the Screen:
 *                      - TabBarPickerPositionLeft : Is positioned in vertical on left of the screen and shows the picker at its right
 *                      - TabBarPickerPositionRight : Is positioned in vertical on right of the screen and shows the picker at its left
 *                      - TabBarPickerPositionBottom : Is positioned in horizontal on bottom of the screen and shows the picker at its top
 *                      - TabBarPickerPositionTop : Is positioned in horizontal on top of the screen and shows the picker at its bottom
 *
 *  @param relation Represents NSLayoutRelation for TabBar layout.
 *
 *  @return raturn instance of TabBarPicker object.
 */
- (instancetype) initWithTabBarItems:(NSArray *) items forPosition:(TabBarPickerPosition) position andNSLayoutRelation:(NSLayoutRelation) relation;

/**
 *  Init TabBarPicker with items. When is selected an item the picher show down subitems.
 *  By default when one of more subItems are selected the selected item become selected.
 *  The picker size is dinamically based the max subitems of items
 *
 *  @param items Represents tab bar items. That array cannot be nil.
 *
 *  @param size  Represents the tabbar size
 *
 *  @param position Represents the posizion in the Screen: 
 *                      - TabBarPickerPositionLeft : Is positioned in vertical on left of the screen and shows the picker at its right
 *                      - TabBarPickerPositionRight : Is positioned in vertical on right of the screen and shows the picker at its left
 *                      - TabBarPickerPositionBottom : Is positioned in horizontal on bottom of the screen and shows the picker at its top
 *                      - TabBarPickerPositionTop : Is positioned in horizontal on top of the screen and shows the picker at its bottom
 *
 *  @param relation Represents NSLayoutRelation for TabBar layout.
 *
 *  @return raturn instance of TabBarPicker object.
 */
- (instancetype) initWithTabBarItems:(NSArray*) items withTabBarSize:(CGSize) size forPosition:(TabBarPickerPosition) position andNSLayoutRelation:(NSLayoutRelation) relation;

/**
 *  Init TabBarPicker with items. When is selected an item the picher show down subitems.
 *  By default when one of more subItems are selected the selected item become selected.
 *  The picker size is dinamically based the max subitems of items
 *
 *  @param items Represents tab bar items. That array cannot be nil.
 *
 *  @param size  Represents the tabbar size
 *
 *  @param position Represents the posizion in the Screen:
 *                      - TabBarPickerPositionLeft : Is positioned in vertical on left of the screen and shows the picker at its right
 *                      - TabBarPickerPositionRight : Is positioned in vertical on right of the screen and shows the picker at its left
 *                      - TabBarPickerPositionBottom : Is positioned in horizontal on bottom of the screen and shows the picker at its top
 *                      - TabBarPickerPositionTop : Is positioned in horizontal on top of the screen and shows the picker at its bottom
 *
 *  @param relation Represents NSLayoutRelation for TabBar layout.
 *
 *  @param subItemsPerRow Represents the number of subItems per single row of subitem picker
 *
 *  @return <#return value description#>
 */
- (instancetype) initWithTabBarItems:(NSArray*) items withTabBarSize:(CGSize) size forPosition:(TabBarPickerPosition) position andNSLayoutRelation:(NSLayoutRelation) relation subItemsPerRow:(NSUInteger)  subItemsPerRow;

/**
 *  Init TabBarPicker with items. When is selected an item the picher show down subitems.
 *  By default when one of more subItems are selected the selected item become selected.
 *  The picker size is dinamically based the max subitems of items
 *
 *  @param items Represents tab bar items. That array cannot be nil.
 *
 *  @param size  Represents the tabbar size
 *
 *  @param position Represents the posizion in the Screen:
 *                      - TabBarPickerPositionLeft : Is positioned in vertical on left of the screen and shows the picker at its right
 *                      - TabBarPickerPositionRight : Is positioned in vertical on right of the screen and shows the picker at its left
 *                      - TabBarPickerPositionBottom : Is positioned in horizontal on bottom of the screen and shows the picker at its top
 *                      - TabBarPickerPositionTop : Is positioned in horizontal on top of the screen and shows the picker at its bottom
 *
 *  @param relation Represents NSLayoutRelation for TabBar layout.
 *
 *  @param subItemsPerRow Represents the number of subItems per single row of subitem picker
 *
 *  @param subItemHeight  Represents the height of single subItem.
 *
 *  @return <#return value description#>
 */
- (instancetype) initWithTabBarItems:(NSArray*) items withTabBarSize:(CGSize) size forPosition:(TabBarPickerPosition) position andNSLayoutRelation:(NSLayoutRelation) relation subItemsPerRow:(NSUInteger)  subItemsPerRow subItemHeight:(CGFloat) subItemHeight;

/**
 *  <#Description#>
 *
 *  @param item <#item description#>
 */
- (void) addItem:(TabBarItem*) item;

- (void) show;

- (void) hide;

@end
