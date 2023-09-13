class PhoneBook {
	char* firstName;
	char* lastName;
	char* middleName;

	char* homePhone;
	char* workPhone;

public:
	PhoneBook();
	PhoneBook(const char* fn, const char* ln, const char* mn, const char* hp, const char* wp);
	~PhoneBook();

	void Input();
	void Print();
	int ResizeArray(PhoneBook*&, int);
	int DeleteSubscriber(PhoneBook*&, int, int);
	int SearchByFullName(PhoneBook* array, int size, const char* fn, const char* ln, const char* mn);
	void SaveToFile(PhoneBook* array, int size);
	void LoadFromFile();

	char* GetFirstName();
	char* GetLastName();
	char* GetMiddleName();
	char* GetHomePhone();
	char* GetWorkPhone();

	void SetFirstName(const char*);
	void SetLastName(const char*);
	void SetMiddleName(const char*);
	void SetHomePhone(const char*);
	void SetWorkPhone(const char*);
};
