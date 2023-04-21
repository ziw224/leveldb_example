#include <iostream>
#include <cassert>
#include "leveldb/db.h"


int main() {
    leveldb::DB* db;

    // Set up the options for opening the database
    leveldb::Options options;
    options.create_if_missing = true;
    options.error_if_exists = false;

    // Open the database
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    // if (!status.ok()) {
    //     std::cerr << status.ToString() << std::endl;
    // }
    assert(status.ok());

    // Put: Insert a key-value pair into the database
    std::string key = "test2";
    std::string value = "hello world";
    status = db->Put(leveldb::WriteOptions(), key, value);

    assert(status.ok());

    // Read: Retrieve the value associated with a key
    std::string retrieved_value;
    status = db->Get(leveldb::ReadOptions(), key, &retrieved_value);
    if (status.ok()) {
        std::cout << "Retrieved value: " << retrieved_value << std::endl;
    } else {
        std::cerr << "Error retrieving value: " << status.ToString() << std::endl;
    }

    // // Delete: Delete a key
    // status = db->Delete(leveldb::WriteOptions(), key);
    // assert(status.ok());

    // status = db->Get(leveldb::ReadOptions(), key, &value);
    // if (!status.ok()) {
    //     cerr << key << "    " << status.ToString() << endl;
    // } else {
    //     cout << key << "===" << value << endl;
    // }


    // Close the database when finished
    delete db;

    return 0;
}
