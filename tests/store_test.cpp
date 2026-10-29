#include "minikv/store.h"

#include <gtest/gtest.h>

namespace minikv {
namespace {

TEST(StoreTest, InitiallyEmpty) {
    Store store;

    EXPECT_EQ(store.size(), 0);
}

TEST(StoreTest, SetAndGetValue) {
    Store store;

    store.set("name", "Harnoor");

    auto value = store.get("name");

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "Harnoor");
}

TEST(StoreTest, GetMissingKeyReturnsNoValue) {
    Store store;

    auto value = store.get("missing");

    EXPECT_FALSE(value.has_value());
}

TEST(StoreTest, SetUpdatesExistingKey) {
    Store store;

    store.set("name", "Alice");
    store.set("name", "Bob");

    auto value = store.get("name");

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "Bob");
    EXPECT_EQ(store.size(), 1);
}

TEST(StoreTest, DeleteExistingKey) {
    Store store;

    store.set("name", "Harnoor");

    EXPECT_TRUE(store.del("name"));
    EXPECT_FALSE(store.get("name").has_value());
    EXPECT_EQ(store.size(), 0);
}

TEST(StoreTest, DeleteMissingKeyReturnsFalse) {
    Store store;

    EXPECT_FALSE(store.del("missing"));
}

TEST(StoreTest, MultipleKeysAreStoredIndependently) {
    Store store;

    store.set("name", "Alice");
    store.set("city", "Kanpur");

    EXPECT_EQ(store.size(), 2);

    ASSERT_TRUE(store.get("name").has_value());
    ASSERT_TRUE(store.get("city").has_value());

    EXPECT_EQ(*store.get("name"), "Alice");
    EXPECT_EQ(*store.get("city"), "Kanpur");
}

TEST(StoreTest, EmptyValueIsDifferentFromMissingKey) {
    Store store;

    store.set("empty", "");

    auto value = store.get("empty");

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "");

    EXPECT_FALSE(store.get("missing").has_value());
}

}  // namespace
}  // namespace minikv