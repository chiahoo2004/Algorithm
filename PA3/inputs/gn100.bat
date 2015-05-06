read_graph gn100.dot 
write_tree_dfs -s v0 -o ../outputs/gn100_dfs.dot
write_tree_bfs -s v0 -o ../outputs/gn100_bfs.dot
color_graph -m greedy -o ../outputs/gn100_color.dot