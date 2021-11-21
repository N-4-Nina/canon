#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

string	upper(string s)
{
	string	up;
	locale loc;

	for (unsigned int i = 0; i < s.length(); i++)
		up.append(1, toupper(s[i], loc));
	return (up);
}

int	write_files(string name, ofstream files[2])
{
	files[0] << "#ifndef " + upper(name) + "_HPP" << endl << "# define " + upper(name) + "_HPP"  << endl << endl << "class " << name <<\
	endl << "{" << endl <<"\tpublic:" << endl << "\t\t" << name << "(void);" << endl << "\t\t" << name << "(const " << name <<\
	" &ref);" << endl << "\t\t" + name << "\t" << "&operator=(const " << name << " &ref);" << endl << "\t\t~" << name << "(void);" <<\
	endl << "\tprivate:" << endl << "\t\tint\tdummy;" << endl << "};" << endl << endl << "#endif";

	files[1] << "#include \"" << name + ".hpp\""  << endl << endl << name + "::" + name + "(void)" << endl << "{" << endl <<\
	"}" << endl << endl << name + "::" + name + "(const " + name + " &ref)" << endl << "{" << endl << "}" << endl <<\
	endl << name + "\t&" + name + "::operator=" + "(const " + name + " &ref)" << endl << "{" << endl << "\treturn (*this);" <<\
	endl << "}" << endl << endl << name + "::" + "~" + name + "(void)" << endl << "{" << endl << "}" << endl;
	
	files[0].close();
	files[1].close();
	return (0);
}