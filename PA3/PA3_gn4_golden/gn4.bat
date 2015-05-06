read_graph inputs/gn4.dot 
dot -Tpng inputs/gn4.dot -o outputs/gn4.png
display outputs/gn4.png
write_tree_dfs -s v0 -o outputs/gn4_dfs.dot
dot -Tpng outputs/gn4_dfs.dot -o outputs/gn4_dfs.png
display outputs/gn4_dfs.png
write_tree_bfs -s v0 -o outputs/gn4_bfs.dot
color_graph -m greedy -o outputs/gn4_color.dot
exit

