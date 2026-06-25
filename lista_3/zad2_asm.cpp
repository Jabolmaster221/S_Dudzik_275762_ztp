struct NormalClass {
	void doWork() {}
};

struct VirtualClass {
	virtual void doWork() {}
};

__attribute__((noinline)) void callNormal(NormalClass* obj) {
	obj->doWork();
}

__attribute__((noinline)) void callVirtual(VirtualClass* obj) {
	obj->doWork();
}