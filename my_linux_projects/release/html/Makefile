all:
	g++ main.cpp -o html

install:
	sudo cp html /usr/bin/
	sudo mkdir /etc/html_default
	sudo cp index.html /etc/html_default/
	sudo cp main.css   /etc/html_default/

uninstall:
	sudo rm /usr/bin/html
	sudo rm /etc/html_default/index.html
	sudo rm /etc/html_default/main.css
	sudo rmdir /etc/html_default


