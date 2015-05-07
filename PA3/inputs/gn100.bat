read_graph inputs/gn100.dot 
dot -Tpng inputs/gn100.dot -o outputs/gn100.png
display outputs/gn100.png
write_tree_dfs -s v0 -o outputs/gn100_dfs.dot
dot -Tpng outputs/gn100_dfs.dot -o outputs/gn100_dfs.png
display outputs/gn100_dfs.png
write_tree_bfs -s v0 -o outputs/gn100_bfs.dot
dot -Tpng outputs/gn100_bfs.dot -o outputs/gn100_bfs.png
display outputs/gn100_bfs.png
color_graph -m greedy -o outputs/gn100_color.dot
exit