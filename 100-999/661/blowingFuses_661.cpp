#include <iostream>
#include <vector>
using namespace std;


class Fuse {
	public:
		int consumption;
		bool on;

		Fuse(int consumption) {
			this->consumption = consumption;
			this->on = false;
		}

		void switchFuse() { on = !on; }
};

int main(){

	int devices, operations, capacity, maxConsumption, c, currentConsumption;
	int sequence = 0;
	vector<Fuse> fuses;

	while(cin >> devices >> operations >> capacity) {
		if (!devices && !operations && !capacity) break;

		sequence++;
		fuses.clear();
		maxConsumption = 0;
		currentConsumption = 0;

		for(int i=0; i<devices; i++) {
			cin >> c;
			fuses.push_back(Fuse(c));
		}

		for(int i=0; i<operations; i++) {
			cin >> c;
			Fuse *f = &fuses[c-1];
			(*f).switchFuse();
			if (f->on) currentConsumption += f->consumption;
			else currentConsumption -= f->consumption;

			if (currentConsumption > maxConsumption) maxConsumption = currentConsumption;
		}

		printf("Sequence %d\n", sequence);
		if (maxConsumption > capacity) cout << "Fuse was blown.\n\n";
		else {
			cout << "Fuse was not blown.\n";
			printf("Maximal power consumption was %d amperes.\n\n", maxConsumption);
		}
	}

	return 0;
}
