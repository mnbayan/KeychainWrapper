//
//  KeychainWrapper.h
//
//  Created by Mylene Bayan on 9/4/14.
//

#import <Foundation/Foundation.h>


/**
 *  This is from tutorial http://www.raywenderlich.com/6603/basic-security-in-ios-5-tutorial-part-2
 */
@interface KeychainWrapper : NSObject

/**
 *  Generic exposed method to search the keychain for a given value.  Limit one result per search.
 *
 *  @param identifier key to be used to search the keychain
 *
 *  @return the value for the given key
 */
+ (NSData *)searchKeychainCopyMatchingIdentifier:(NSString *)identifier;

/**
 *   Calls searchKeychainCopyMatchingIdentifier: and converts to a string value.
 *
 *  @param identifier the key to be used to search the keychain
 *
 *  @return the value for a given key
 */
+ (NSString *)keychainStringFromMatchingIdentifier:(NSString *)identifier;

/**
 *  Default initializer to store a value in the keychain.
 *  Associated properties are handled for you (setting Data Protection Access, Company Identifer (to uniquely identify string, etc).
 *
 *  @param value      the value to be saved in the keychain
 *  @param identifier the key to be used in accessing the value
 *
 *  @return boolean; YES if value has been saved/updated; NO if the value encountered error while saving/updating
 */
+ (BOOL)createKeychainValue:(NSString *)value forIdentifier:(NSString *)identifier;

/**
 *  Updates a value in the keychain.  If you try to set the value with createKeychainValue: and it already exists
 *  this method is called instead to update the value in place.
 *
 *  @param value      the new value to be saved
 *  @param identifier the key for the value to be updated
 *
 *  @return boolean; YES if update succeeded; NO if update failed
 */
+ (BOOL)updateKeychainValue:(NSString *)value forIdentifier:(NSString *)identifier;

/**
 *  Deletes a value in the keychain
 *
 *  @param identifier the key of the value/item to be deleted
 */
+ (void)deleteItemFromKeychainWithIdentifier:(NSString *)identifier;

/**
 *  Deletes all items in keychain
 */
+ (void)resetKeychain;

@end
