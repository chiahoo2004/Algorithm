read_graph gn10.dot 
write_tree_dfs -s v0 -o ../outputs/gn10_dfs.dot
write_tree_bfs -s v0 -o ../outputs/gn10_bfs.dot
color_graph -m greedy -o ../outputs/gn10_color.dot