read_graph inputs/gn8.dot 
dot -Tpng inputs/gn8.dot -o outputs/gn8.png
display outputs/gn8.png
write_tree_dfs -s v0 -o outputs/gn8_dfs.dot
dot -Tpng outputs/gn8_dfs.dot -o outputs/gn8_dfs.png
display outputs/gn8_dfs.png
write_tree_bfs -s v0 -o outputs/gn8_bfs.dot
dot -Tpng outputs/gn8_bfs.dot -o outputs/gn8_bfs.png
display outputs/gn8_bfs.png
color_graph -m greedy -o outputs/gn8_color.dot
exit