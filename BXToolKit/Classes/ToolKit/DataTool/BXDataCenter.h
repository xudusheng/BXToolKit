//
//  BXDataCenter.h
//  BXDataTool
//
//  Created by ayi on 2018/5/14.
//  Copyright © 2018 ayi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BXDataCenter : NSObject
/**
 设置数据库文件的名字，无需带后缀名
 请在初始化之前调用该方法进行设置，否则默认设置为“BISINUOLAN”

 @param dataBaseName 数据库文件的名字
 */
+ (void)setDataBaseName:(NSString *)dataBaseName;

/**
 在document文件夹中创建默认数据库BIXUAN.sqlite
 @return BSNL_FMDBTool
 */
+ (BXDataCenter *)shareCenter;

#pragma mark - create

/**
 创建表
 @param obj 类
 @param tableName 表名
 @param key 主键（不传的话会创建默认主键 primaryKey）
 */
- (BOOL)createTableWithClass:(Class)obj andTableName:(NSString *)tableName andPrimaryKey:(NSString *)key;

/**
 创建表
 
 @param sql 创建表的sql语句
 @param tableName 表名
 */
- (BOOL)createTableWithSql:(NSString *)sql andTableName:(NSString *)tableName;

#pragma mark - clear
// 删除表
- (BOOL)deleteTable:(NSString *)tableName;
// 清空表
- (BOOL)deleteAllDataFromTable:(NSString *)tableName;

#pragma mark - insert

/**
 插入单条数据
 
 @param obj 实例对象
 @param tableName 表名
 */
- (BOOL)insertData:(NSDictionary *)obj inTableName:(NSString *)tableName;

/**
 插入多条数据
 
 @param array 实例对象数组
 @param tableName 表名
 */
- (BOOL)insertDataArray:(NSArray *)array inTableName:(NSString *)tableName;

#pragma mark - delete

/**
 删除数据
 
 @param tableName 表名
 @param conditions 条件
 */
- (BOOL)deleteDataWithTableName:(NSString *)tableName conditions:(NSDictionary *)conditions;

#pragma mark - select
/**
 *  查询方法 若不需要某参数，置为nil
 *
 *  @param tableName  表格名称
 *  @param conditions 需要查询的条件字典 属性名称为key 值为obj(若需要查询多个值用IN关键字时，obj为NSArray)
 *  @return 查询结果
 */
- (NSArray *)selectDataWithTableName:(NSString *)tableName conditions:(NSDictionary *)conditions;

/**
 *  查询方法 若不需要某参数，置为nil
 *
 *  @param tableName  表格名称
 *  @param conditions 需要查询的条件字典 属性名称为key 值为obj(若需要查询多个值用IN关键字时，obj为NSArray)
 *  @param orderBy    排序字段参数（若排序字段为nil，则不进行排序）, 按照参数顺序作为排序的优先顺序，先排序数组中0位置的参数
 *                    数组内容为NSDictionary,带有两个参数 nsstring order_name 排序的属性名称, nsnumber(bool) order_is_asc 排序是否递增排序
 *  @return 查询结果
 */
- (NSArray *)selectDataWithTableName:(NSString *)tableName conditions:(NSDictionary *)conditions orderBy:(NSArray *)orderBy;

/**
 *  查询方法 若不需要某参数，置为nil
 *
 *  @param tableName  表格名称
 *  @param conditions 需要查询的条件字典 属性名称为key 值为obj(若需要查询多个值用IN关键字时，obj为NSArray)
 *  @param orderBy    排序字段参数（若排序字段为nil，则不进行排序）, 按照参数顺序作为排序的优先顺序，先排序数组中0位置的参数
 *                    数组内容为NSDictionary,带有两个参数 nsstring order_name 排序的属性名称, nsnumber(bool) order_is_asc 排序是否递增排序
 *  @param range      截取指定序号的数据
 *
 *  @return 查询结果
 */
- (NSArray *)selectDataWithTableName:(NSString *)tableName conditions:(NSDictionary *)conditions orderBy:(NSArray *)orderBy limit:(NSRange)range;




#pragma mark - update

/**
 更新数据
 
 @param obj 实例对象
 @param tableName 表名
 @param conditions 条件
 */
- (BOOL)updateData:(NSDictionary *)obj inTableName:(NSString *)tableName conditions:(NSDictionary *)conditions;

#pragma mark - search

/**
 关键字搜索相关
 
 @param tableName 表名
 @param conditionSql 条件sql
 */
- (NSArray *)searchDataWithTableName:(NSString *)tableName conditionSql:(NSString *)conditionSql;

@end
