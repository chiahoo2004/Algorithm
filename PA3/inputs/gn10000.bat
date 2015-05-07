read_graph inputs/gn10000.dot 
dot -Tpng inputs/gn10000.dot -o outputs/gn10000.png
display outputs/gn10000.png
write_tree_dfs -s v0 -o outputs/gn10000_dfs.dot
dot -Tpng outputs/gn10000_dfs.dot -o outputs/gn10000_dfs.png
display outputs/gn10000_dfs.png
write_tree_bfs -s v0 -o outputs/gn10000_bfs.dot
dot -Tpng outputs/gn10000_bfs.dot -o outputs/gn10000_bfs.png
display outputs/gn10000_bfs.png
color_graph -m greedy -o outputs/gn10000_color.dot
exit