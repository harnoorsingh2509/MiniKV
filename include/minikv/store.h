#ifndef MINIKV_STORE_H
#define MINIKV_STORE_H

#include <cstddef>
#include <optional>
#include <string>
#include <unordered_map>

namespace minikv {

class Store {
public:
    // Insert a new key or update an existing key.
    void set(const std::string& key, const std::string& value);

    // Return the value if the key exists.
    std::optional<std::string> get(const std::string& key) const;

    // Delete a key. Return true if it existed.
    bool del(const std::string& key);

    // Return the number of stored keys.
    std::size_t size() const;

private:
    std::unordered_map<std::string, std::string> data_;
};

}  // namespace minikv

#endif