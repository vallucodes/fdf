https://wiki.wxwidgets.org/Valgrind_Suppression_File_Howto

valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=./minimal.supp ./fdf maps/10-2.fdf
