/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/



class Solution {
public:
    int isvalid( int l , int r , int t , int b , vector<vector<int>> &grid )
    {
        int ele = grid[l][t];
        for( int i = l ; i <=r ; ++i )
        {
            for( int j = t ; j <= b ; ++j )
            {
                if(grid[i][j]!=ele) return -1;
            }
        }
        return ele;
    }
    vector<vector<int>> childs(int l , int r , int t , int b )
    {

         int mid1 = (l+r)/2;
         int mid2 = (t+b)/2;
         
         vector<vector<int>> ans = { 
             {l,mid1,t,mid2}, // top left 
             {l,mid1,mid2+1,b},//top right 
             {mid1+1,r,t,mid2},//bottom left 
             {mid1+1,r,mid2+1,b} // bottom right 
         };
         return ans;

    }
    Node* fun(int l , int r , int t , int b , vector<vector<int>> &grid)
    {      int ele = isvalid(l,r,t,b,grid);
            if(ele != -1)
            {
                  Node *node = new Node(ele,true);
                  return node;
            }

            Node *node = new Node(1,false);
           
            vector<vector<int>> adj = childs(l,r ,t , b );
        cout<<l<<" "<<r<<" "<<t<<" "<<b<<" \n";
        node->topLeft = fun(adj[0][0],adj[0][1],adj[0][2],adj[0][3],grid);
        node->topRight = fun(adj[1][0],adj[1][1],adj[1][2],adj[1][3],grid);
        node->bottomLeft = fun(adj[2][0],adj[2][1],adj[2][2],adj[2][3],grid);
        node->bottomRight = fun(adj[3][0],adj[3][1],adj[3][2],adj[3][3],grid);
            
        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        return fun(0,n-1,0,m-1,grid);
    }
};