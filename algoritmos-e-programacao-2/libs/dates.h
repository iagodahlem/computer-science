/*
 * DATE'S LIB                          
 *
 * By @iagodahlem under MIT license
 */


// Functions Definition
// -------------------------------------

int validDate(int day, int month, int year);


// Functions
// -------------------------------------

int validDate(int day, int month, int year) {
	int isValid;

	if (year > 0) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day >= 1 && day <= 31) {
				isValid = 1;
			}
		} else {
		    if (month == 4 || month == 6 || month == 9 || month == 11 ) {
		      	if (day >= 1 && day <= 30) {
			    	isValid = 1;
		      	}
		    }
		    else {
		        if (month == 2) {
		           	if (day >= 1 && day <= 28) {
			           	isValid = 1;
		           	} else {
		        	   if (y % 4 == 0 && day >= 1 && day <= 29) {
			              	isValid = 1;
		        	   	}
		           	}
		        } else {
			        isValid = 0;
		        }
		    }
		}
	} else {
		isValid = 0;
	}

	return isValid;
}
