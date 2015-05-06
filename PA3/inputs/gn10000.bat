read_graph gn10000.dot 
write_tree_dfs -s v0 -o ../outputs/gn10000_dfs.dot
write_tree_bfs -s v0 -o ../outputs/gn10000_bfs.dot
color_graph -m greedy -o ../outputs/gn10000_color.dot