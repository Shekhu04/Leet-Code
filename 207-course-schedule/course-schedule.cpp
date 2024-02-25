class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);

//vector to keep track how many edges are incoming to a given node


        vector<vector<int>>graph(numCourses);
// graph to keep track of all the node and its 
//neighbour relation 

        for(vector<int> req:prerequisites){
            int from=req[0];
            int to=req[1];
            graph[from].push_back(to);

// pushing neighbours for each node so that 
//later i can easily visit referencing to node 

            indegree[to]++;

// we have one edge incoming so we have to increment 
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);

//Unreachable course will have to include it personally marketing  
 //needed
            }

        }
        int nodestraversed=0;
// count of how many courses completed 
        while(!q.empty()){
            int node=q.front();
            q.pop();
            nodestraversed++; 
//one course completed 

            for(int nei:graph[node]){
                if(--indegree[nei]==0){
// going from one course to another if it is also not famous called 
//course hell sed life 
                    q.push(nei);
                }
            }
        }
        return nodestraversed==numCourses;
//Was i able to complete all the courses and still not able to get 
//internship 


    }
};