import std.stdio;
import std.string;

char maint() {
	writeln("Returning some shit...");
	return 'a';//toStringz("This is an example");
}

// int main () {
// 	writeln("FHEJK");
// 	return 0;
// }

//extern (C++) {
	extern (C++) char foo() {
		return maint();
	}
//}