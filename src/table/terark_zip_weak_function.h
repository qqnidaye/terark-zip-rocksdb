/*
 * terark_zip_weak_function.h
 *
 *  Created on: 2017-04-01
 *      Author: leipeng
 */

#ifndef TABLE_TERARK_ZIP_WEAK_FUNCTION_H_
#define TABLE_TERARK_ZIP_WEAK_FUNCTION_H_
#pragma once

#include "terark_zip_table.h"

namespace rocksdb {

#if !defined(_MSC_VER)

void
__attribute__((weak))
TerarkZipAutoConfigForBulkLoad(struct TerarkZipTableOptions&,
                               struct DBOptions&,
                               struct ColumnFamilyOptions&,
                               size_t cpuNum,
                               size_t memBytesLimit,
                               size_t diskBytesLimit);

void
__attribute__((weak))
TerarkZipAutoConfigForOnlineDB(struct TerarkZipTableOptions&,
                               struct DBOptions&,
                               struct ColumnFamilyOptions&,
                               size_t cpuNum,
                               size_t memBytesLimit,
                               size_t diskBytesLimit);

void
__attribute__((weak))
TerarkZipAutoConfigForOnlineDB_DBOptions(struct DBOptions& dbo, size_t cpuNum);

void
__attribute__((weak))
TerarkZipAutoConfigForOnlineDB_CFOptions(struct TerarkZipTableOptions& tzo,
                                    struct ColumnFamilyOptions& cfo,
                                    size_t memBytesLimit,
                                    size_t diskBytesLimit);

const class WriteBatchEntryIndexFactory*
__attribute__((weak))
WriteBatchEntryPTrieIndexFactory(const WriteBatchEntryIndexFactory* fallback);

class MemTableRepFactory*
__attribute__((weak))
NewPatriciaTrieRepFactory(std::shared_ptr<class MemTableRepFactory> fallback);

class TableFactory*
__attribute__((weak))
NewTerarkZipTableFactory(const TerarkZipTableOptions&,
                         std::shared_ptr<class TableFactory> fallback);

std::shared_ptr<class TableFactory>
__attribute__((weak))
SingleTerarkZipTableFactory(const TerarkZipTableOptions&,
                            std::shared_ptr<class TableFactory> fallback);


bool
__attribute__((weak))
TerarkZipConfigFromEnv(struct DBOptions&,
                       struct ColumnFamilyOptions&);

bool __attribute__((weak)) TerarkZipCFOptionsFromEnv(struct ColumnFamilyOptions&);
void __attribute__((weak)) TerarkZipDBOptionsFromEnv(struct DBOptions&);

bool __attribute__((weak)) TerarkZipIsBlackListCF(const std::string& cfname);

void __attribute__((weak))
TerarkZipMultiCFOptionsFromEnv(const struct DBOptions& db_options,
      const std::vector<struct ColumnFamilyDescriptor>& cfvec);

#endif // _MSC_VER

} // namespace rocksdb

#endif /* TABLE_TERARK_ZIP_WEAK_FUNCTION_H_ */
