#include <iostream>
#include <vector>
#include <algorithm>

enum Room {
    locked,
    currently_in,
    visited,
};

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int32_t>>& rooms) {
        std::vector<Room> visited(rooms.size(), Room::locked);

        DFS(rooms, visited, 0);

        return std::all_of(visited.begin(), visited.end(), [](int room) {
            return room == Room::visited;
        });
    }

    void DFS(std::vector<std::vector<int32_t>>& rooms, std::vector<Room>& visited, int32_t room) {
        visited[room] = Room::currently_in;

        for (int32_t key: rooms[room]) {
            if (visited[key] == Room::locked) {
                DFS(rooms, visited, key);
            }
        }

        visited[room] = Room::visited;
    }
};
