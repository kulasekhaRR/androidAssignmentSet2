#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ModuleDependencyChecker {
public:
    bool hasCircularDependency(int totalModules, const vector<vector<int>>& dependencies) {
        unordered_map<int, vector<int>> adjacencyList;

        // Create the graph
        for (const auto& dep : dependencies) {
            int from = dep[0];
            int to = dep[1];
            adjacencyList[from].push_back(to);
        }

        vector<bool> visited(totalModules, false);
        vector<bool> inRecursion(totalModules, false);

        // Run DFS for each module
        for (int i = 0; i < totalModules; ++i) {
            if (!visited[i]) {
                if (dfsHasCycle(i, adjacencyList, visited, inRecursion)) {
                    return true; // Found a cycle
                }
            }
        }

        return false; // No cycles found
    }

private:
    bool dfsHasCycle(int node, const unordered_map<int, vector<int>>& graph,
                     vector<bool>& visited, vector<bool>& inStack) {
        visited[node] = true;
        inStack[node] = true;

        auto it = graph.find(node);
        if (it != graph.end()) {
            for (int neighbor : it->second) {
                if (!visited[neighbor]) {
                    if (dfsHasCycle(neighbor, graph, visited, inStack)) {
                        return true;
                    }
                } else if (inStack[neighbor]) {
                    return true; // Cycle detected
                }
            }
        }

        inStack[node] = false; // Backtrack
        return false;
    }
};

int main() {
    int modules, dependencyCount;
    cout << "Enter number of modules: ";
    cin >> modules;

    cout << "Enter number of dependencies: ";
    cin >> dependencyCount;

    vector<vector<int>> dependencies;
    cout << "Enter dependencies in the format (a b) meaning 'a depends on b':\n";
    for (int i = 0; i < dependencyCount; ++i) {
        int a, b;
        cin >> a >> b;
        dependencies.push_back({a, b});
    }

    ModuleDependencyChecker checker;
    bool result = checker.hasCircularDependency(modules, dependencies);

    cout << (result ? "True" : "False") << endl;
    return 0;
}
