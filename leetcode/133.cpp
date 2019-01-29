void dfs(UndirectedGraphNode * g, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &ht, unordered_set<UndirectedGraphNode *> &vis) {
        if(g == NULL) return;
                
        ht[g] = new UndirectedGraphNode(g->label);;
        vis.insert(g);
        
        for(int i = 0; i < g->neighbors.size(); i++) {
            if(vis.find(g->neighbors[i]) == vis.end()) dfs(g->neighbors[i], ht, vis);
            ht[g]->neighbors.push_back( ht[ g->neighbors[i] ]);
        }
}
    
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return node;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> ht;
        unordered_set<UndirectedGraphNode *> vis;
                
        dfs(node, ht, vis);
        
        return ht[node];
}
