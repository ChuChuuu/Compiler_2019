int try(int input){
	int a = 20;
	if (a == 40){
        print("a is equal to 40");
    }
    else if (a > 40){
        print("a is larger than 40");
    }
    else{
        print(666);
    }
	//
	print("--------------");
	if( a > 20 ){
		print(1);
	}
	else{
		if( a > 30){
			print(2);
		}
		else{
			print(3);
		}
		if( a < 20){
			print(4);
		}
	}
	print("-------------");
	if( a == 20){
		if( a!=20){
			print(6);
		}
		else{
			if(a == 20){
				print(7);
				if( a != 20){
					print(10);
				}
				else{
					print(11);
					int cc = 0;
					while(cc < 10){
						int xx = cc%2;
						if(xx == 0){
							print("even");
							print(cc);
						}
						else{
							print("odd");
							print(cc);
						}
						cc++;
					}
				}
			}
			else{
				print(8);
			}
			if(a != 20){
				print(9);
			}
			else{
				print(12);
			}
		}
	}
	else{
		print("nohere");
	}
	if(input > 10){
		print(">10return0");
		return 0;
	}
	else if( input < 5){
		print("<5return1");
		return 1;
	}
	else{
		print(">5<=10return2");
		return 2;
	}
	return 7;
}
void main(){
	int this=2;
	print(this);
	this = try(this);
	print(this);
	return;
}
/*
void main(){
	int a = 20;
	if (a == 40){
        print("a is equal to 40");
    }
    else if (a > 40){
        print("a is larger than 40");
    }
    else{
        print(666);
    }
	
	return;
}
*/
