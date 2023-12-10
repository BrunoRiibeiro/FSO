#include <stdio.h>
#include <deque>

void LRU(std::deque<int> &dq, int lastone) {
	auto search = std::find(dq.begin(), dq.end(), lastone); 
	std::rotate(search, std::next(search), dq.end());
}

int main() {
	int q, pages, pickpage, page_faults = 0;
	scanf("%d\n%d\n%d", &q, &pages, &pickpage);
	std::deque<int> qq;
	qq.push_back(pickpage);
	page_faults++, pages--;
	while (pages) {
		scanf("%d", &pickpage);
		if (std::find(qq.begin(), qq.end(), pickpage) == qq.end()) {
			if (qq.size() != q)
				qq.push_back(pickpage);
			else{
				qq.pop_front();
				qq.push_back(pickpage);
			}
			page_faults++;
		} else LRU(qq, pickpage);
		pages--;
	}
	printf("%d\n", page_faults);
	return 0;
}
