struct ConnectedComponents {
    int count;              // quantidade de componentes
    vector<int> id;         // id[v] = componente do vértice v
    vector<int> size;       // size[c] = tamanho da componente c
};

ConnectedComponents connected_components(
    const vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<int> id(n, -1);
    vector<int> component_size;

    int components = 0;

    for (int start = 0; start < n; ++start) {
        if (id[start] != -1) continue;

        stack<int> st;
        st.push(start);
        id[start] = components;

        int current_size = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            ++current_size;

            for (int v : graph[u]) {
                if (id[v] == -1) {
                    id[v] = components;
                    st.push(v);
                }
            }
        }

        component_size.push_back(current_size);
        ++components;
    }

    return {components, id, component_size};
}
