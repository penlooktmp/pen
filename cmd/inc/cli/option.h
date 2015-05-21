
#include <iostream>
#include <functional>

#define option_callback function<void(string)>

using namespace std;

namespace cli {
	class Option {
	private:
		string name;
		string description;
		string param;
		option_callback callback;
		
	public:
		Option &setName(string _name) {
			name = _name;
			return *this;
		}
		
		Option &setDescription(string _desc) {
			description = _desc;
			return *this;	
		}
		
		Option setParam(string _param) {
			param = _param;
			return *this;
		}
		
		Option &setCallback(option_callback _callback) {
			callback = _callback;
			return *this;
		}
		
		string getName() {
			return name;
		}
		
		string getDescription() {
			return description;
		}
		
		string getParam() {
			return param;
		}
		
		option_callback getCallback() {
			return callback;
		}
	};
}
