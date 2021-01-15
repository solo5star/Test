#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <sstream>
#include <regex>

using namespace std;

bool empty(stringstream& ss) {
	return ss.rdbuf()->in_avail() == 0;
}

bool validate(string& str) {
	int n = str.length();

	// <~~~~>
	string tag;
	stringstream tagBuilder;
	// &~~~
	string escape;
	stringstream escapeBuilder;
	// context of tags
	stack<string> context;

	bool closed;
	bool isClosingTag;
	bool selfClosedTag;
	
	for (int i = 0; i < n; i++) {
		switch (str[i]) {
		case '&':
			closed = false;
			for(i++; i < n; i++) {
				if (str[i] == ';') {
					closed = true; break;
				}
				escapeBuilder << str[i];
			}
			if (!closed) return false;

			escape = escapeBuilder.str();

			// check for &lt;, &gt;, &amp;
			if (escape == "lt" || escape == "gt" || escape == "amp") {
				// valid!
			}
			// check for &x~~~~;
			else if (escape[0] == 'x') {
				int countHex = 0;
				for (int j = 1; j < escape.length(); j++) {
					if (!(
						('0' <= escape[j] && escape[j] <= '9')
						|| ('A' <= escape[j] && escape[j] <= 'F')
						|| ('a' <= escape[j] && escape[j] <= 'z')
					)) {
						return false;
					}
					countHex++;
				}
				// hex are must be even counts (2, 4, ...)
				if (countHex % 2 != 0) return false;

				// valid!
			}
			// invalid use of &
			else {
				return false;
			}

			escapeBuilder.str("");
			break;

		case '<':
			// </~~~~>
			isClosingTag = false;
			selfClosedTag = false;
			closed = false;

			for(i++; i < n; i++) {
				if (str[i] == '<') return false;
				else if (str[i] == '>') {
					closed = true; break;
				}
				else if (str[i] == '/') {
					// </~~~~>
					if (str[i - 1] == '<') {
						isClosingTag = true;
					}
					// <~~~~/>
					else if (i + 1 < n && str[i + 1] == '>') {
						if (isClosingTag) return false;

						selfClosedTag = true; continue;
					}
					else {
						return false;
					}
				}
				else if (!(
					('0' <= str[i] && str[i] <= '9')
					|| ('a' <= str[i] && str[i] <= 'z')
				)) {
					return false;
				}
				else {
					tagBuilder << str[i];
				}

			}
			if (!closed) return false;

			tag = tagBuilder.str();

			if (selfClosedTag) {

			}
			else if (!isClosingTag) {
				context.push(tag);
			}
			else {
				// Did not match with previous tag
				if (context.empty() || context.top() != tag) return false;
				context.pop();
			}

			tagBuilder.str("");
			break;

		case '>':
			return false;
		}
	}

	return context.empty();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string line;

	while (!cin.eof()) {
		getline(cin, line);

		cout << (validate(line) ? "valid" : "invalid") << "\n";
	}
}