#include <map>
#include <set>
#include <string>
#include <unordered_map>


std::unordered_map<int, int> just_hashmap;
// faster than std::map

std::map<int, int> hashmap_with_sorted_keys;
// uses red-black binary tree to sort keys


// 2.
namespace std {
    template<>
    struct hash<somestruct>
    {
        size_t operator()(const somestruct& key)
        {
            return hash<std::string>()(key.unique_identifier);
        }
    };
}


// key type must be hashable (std::hash<smth>): int, std::string, ...
// if the key is not hashable by itself:
struct somestruct {
    std::string unique_identifier;
};


int main() 
{
    // 1. use pointer, because pointer - uint64_t
    std::map<somestruct*, int> hashmap_with_pointer_key;
    // hashmap_with_pointer_key[somestruct{ "lol_town" }] = 1885; ????????????????


    // 2. create a template specialization
    std::map<somestruct, int> hashmap_with_template_specialization;
    hashmap_with_template_specialization[somestruct{ "lol_town" }] = 1885;


    just_hashmap[20] = 'a';
    just_hashmap[2];            // will create key 2 with undentified value
    just_hashmap.at(1);         // will throw an error and won't create any key

    std::set<int> set_is_a_hashmap = {6, 10, 5, 1}; // defining a set with values
    set_is_a_hashmap.insert(2);

    return 0;
};