//
//  NOAPICachedStore.h
//  NetworkObjects
//
//  Created by Alsey Coleman Miller on 11/16/13.
//  Copyright (c) 2013 CDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NetworkObjects/NOAPI.h>
#import <NetworkObjects/NOResourceProtocol.h>
#import <CoreData/CoreData.h>

@interface NOAPICachedStore : NSObject

@property NOAPI *api;

// must initialize the persistent store coordinator

@property (readonly) NSManagedObjectContext *context;

#pragma mark - Requests

-(NSURLSessionDataTask *)getResource:(NSString *)resourceName
                          resourceID:(NSUInteger)resourceID
                          completion:(void (^)(NSError *error, NSManagedObject<NOResourceKeysProtocol> *resource))completionBlock;

-(NSURLSessionDataTask *)editResource:(NSManagedObject<NOResourceKeysProtocol>*)resource
                              changes:(NSDictionary *)values
                           completion:(void (^)(NSError *error))completionBlock;

-(NSURLSessionDataTask *)deleteResource:(NSManagedObject<NOResourceKeysProtocol>*)resource
                             completion:(void (^)(NSError *error))completionBlock;

-(NSURLSessionDataTask *)createResource:(NSString *)resourceName
                          initialValues:(NSDictionary *)initialValues
                             completion:(void (^)(NSError *error, NSManagedObject<NOResourceKeysProtocol> *resource)) completionBlock;

-(NSURLSessionDataTask *)performFunction:(NSString *)functionName
                              onResource:(NSManagedObject<NOResourceKeysProtocol>*)resource
                          withJSONObject:(NSDictionary *)jsonObject
                              completion:(void (^)(NSError *error, NSNumber *statusCode, NSDictionary *jsonResponse))completionBlock;

@end
