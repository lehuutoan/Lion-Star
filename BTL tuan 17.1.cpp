#include<bits/stdc++.h>

using namespace std;

// Building Adjacent Matrix
class AdjMatrixGraph {
private:
    bool** adjMatrix;
    int v;

    bool *visitedDFS; //searching DFS
    bool *visitedBFS; //searching BFS

public:
    // Initialize the matrix to zero
    AdjMatrixGraph(int v) {
        this->v = v;
        adjMatrix = new bool*[v];
        for (int i = 0; i < v; i++) {
            adjMatrix[i] = new bool[v];
            for (int j = 0; j < v; j++)
                adjMatrix[i][j] = false;
        }

        visitedDFS = new bool[v];
        visitedBFS = new bool[v];
    }

    // Add edges
    void addEdge(int u, int w) {
        adjMatrix[u][w] = true;
        adjMatrix[w][u] = true;
    }

      // Remove edges
    void removeEdge(int u, int w) {
        adjMatrix[u][w] = false;
        adjMatrix[w][u] = false;
    }

      // Print the martix
    void toString() {
        cout << "    ";
        for(int i = 0; i < v; i++)
            cout << i << ' ';
        cout << endl;
        for (int i = 0; i < v; i++) {
            cout << i << " : ";
            for (int j = 0; j < v; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    // DFS
    void DFS(int s){
        cout << s << " ";

        visitedDFS[s] = true;

        for (int i = 0; i < v; i++) {
            if (adjMatrix[s][i] == 1 && (!visitedDFS[i])) {
                DFS(i);
            }
        }
    }

    // BFS
    void BFS(int s) {
        vector<int> q;
        q.push_back(s);

        for (int i = 0; i < v; i++) {
            visitedBFS[i] = false;
        }
        visitedBFS[s] = true;

        int mark;
        while(!q.empty()) {
            mark = q[0];

            cout << mark << ' ';
            q.erase(q.begin());

            for (int i = 0; i < v; i++) {
                if (adjMatrix[mark][i] == 1 && (!visitedBFS[i])) {
                    q.push_back(i);
                    visitedBFS[i] = true;
                }
            }
        }
    }

    void findAllPaths(int src, int des){

    }
};

// Building graph with adjacent list
class AdjListGraph {
private:
    int v;
    vector<int> *adjList;
public:
    AdjListGraph(int v){
        this->v = v;
        adjList = new vector<int>[v];
    }

    //Add edges
    void addEdge(int u, int w){
        adjList[u].push_back(w);
        adjList[w].push_back(u);
    }

    //Print the list
    void toString(){
        for (int i = 0; i < v; i++) {
            cout << i << ' ';
            for (auto e : adjList[i])
                cout << "-> " << e << ' ';
            cout << endl;
        }
    }

    // Check visit
    int checkVisited(int x, vector<int>& path)
    {
        for (int i = 0; i < path.size(); i++)
            if (path[i] == x)
                return 0;
        return 1;
    }

    // Finding all ways using BFS
    void findAllPaths(int src, int des){
        queue<vector<int>>q; // queue save the ways

        vector<int> path; // queue save present state
        path.push_back(src);
        q.push(path);

        while(!q.empty()) {
            path = q.front();
            q.pop();
            int last = path[path.size()-1];

            // print way if last is the destination
            if (last == des) {
                cout << " - ";
                for (int i = 0; i < path.size(); i++)
                    cout << path[i] << " ";
                cout << endl;
            }

            for (int i = 0; i < adjList[last].size(); i++) {
                if (checkVisited(adjList[last][i], path)) {
                    vector<int> newpath(path);
                    newpath.push_back(adjList[last][i]);
                    q.push(newpath);
                }
            }
        }
    }
};
int main()
{
    /** Do thi ap dung cho chom sao Su tu co cac dinh da duoc ki hieu
        lai trong file Word*/

    // DO THI CHOM SAO SU TU VOI DANH SACH KE
    AdjListGraph Leo2(9);
    Leo2.addEdge(0, 1);
    Leo2.addEdge(0, 2);
    Leo2.addEdge(1, 5);
    Leo2.addEdge(1, 2);
    Leo2.addEdge(2, 3);
    Leo2.addEdge(3, 4);
    Leo2.addEdge(4, 5);
    Leo2.addEdge(5, 6);
    Leo2.addEdge(6, 7);
    Leo2.addEdge(7, 8);

    cout << "Do thi duoc bieu dien theo danh sach lan can:" << endl;
    Leo2.toString();

    cout << "\n\n";

    // DO THI CHOM SAO SU TU VOI MA TRAN KE
    AdjMatrixGraph Leo1(9);

    Leo1.addEdge(0, 1);
    Leo1.addEdge(0, 2);
    Leo1.addEdge(1, 5);
    Leo1.addEdge(1, 2);
    Leo1.addEdge(2, 3);
    Leo1.addEdge(3, 4);
    Leo1.addEdge(4, 5);
    Leo1.addEdge(5, 6);
    Leo1.addEdge(6, 7);
    Leo1.addEdge(7, 8);

    cout << "Do thi duoc bieu dien theo ma tran ke: " << endl;
    Leo1.toString();

    //searching DFS
    cout << "\nDuyet do thi theo thuat toan tim kiem theo chieu sau: " << endl;
    Leo1.DFS(5); //start with num 5

    //searching BFS
    cout << "\nDuyet do thi theo thuat toan tim kiem theo chieu rong: " << endl;
    Leo1.BFS(5); //start with num 5

    cout << "\nTat ca duong di co the di tu diem duoi Beta den diem mui su tu Epsilon la: " << endl;
    Leo2.findAllPaths(0, 8); // dinh 0 la Beta, dinh 8 la Epsilon
}
