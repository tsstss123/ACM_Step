const int BUFFER_MAX_SIZE = 100000;
struct Quick_In{
	char buf[BUFFER_MAX_SIZE], *ps = buf, *pe = buf + 1;
	inline void InNext(){
		if(++ps == pe)
			pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
	}
	template<class T>
	inline bool operator()(T &number){
		number = 0;
		T f = 1;
		if(ps == pe)return false; // EOF
		do {
			InNext();
			if('-' == *ps) f = -1;
		}while(!isdigit(*ps) && ps != pe);
		if(ps == pe) return false;
		do {
			number = (number << 1) + (number << 3) + *ps - 48;
			InNext();
		}while(isdigit(*ps) && ps != pe);
		number *= f;
		return true;
	}
} In;
struct Quick_Out{
	char buf[BUFFER_MAX_SIZE], *ps = buf, *pe = buf + BUFFER_MAX_SIZE;
	inline void write(){
		fwrite(buf, sizeof(char), ps - buf, stdout);
		ps = buf;
	}
	inline void oc(char c){
		*(ps++) = c;
		if(ps == pe) write();
	}
	inline void os(char *s){
		for(int i = 0; s[i]; ++i) oc(s[i]);
	}
	template<class T>
	inline void oi(T x){
		if(!x) {
			oc('0');
			return ;
		}
		if(x < 0) oc('-'), x = -x;
		char tmp[30];
		int len = 0;
		while(x){
			tmp[len++] = x % 10 + '0';
			x /= 10;
		}
		while(len){
			--len;
			oc(tmp[len]);
		}
	}
	~Quick_Out(){write();}
} Out;
