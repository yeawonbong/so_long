all :
	make -C get_next_line
	cp ./get_next_line/get_next_line.a .

fclean : 
	make fclean -C get_next_line
	rm -f *.a
	rm -f *.o
	rm -f a.out

re : fclean all