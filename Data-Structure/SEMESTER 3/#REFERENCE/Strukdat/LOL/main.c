#include "header.h"

int main(){
	list L;
	createList(&L);
	addFirstB("1403356","FSA",&L);
	addFirstK("IK201","90",L.first);
	// addFirstK("IK202","90",&L);
	// addFirstK("IK203","90",&L);
	// addFirstB("1403355","RSA",&L);
	// addFirstK("IK202","80",&L);
	// addFirstK("IK203","80",&L);
	printElemen(L);
	return 0;
}
