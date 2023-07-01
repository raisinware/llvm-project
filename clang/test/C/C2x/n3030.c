// RUN: %clang_cc1 -std=c2x -Wall -pedantic -verify %s

enum flags : unsigned short {
	a = 0x01,
	b = 0x8000,
	c = 0x10000, // expected-error {{enumerator value is not representable in the underlying type 'unsigned short'}}
	d = 0xFFFF,
	e // expected-error {{enumerator value 65536 is not representable in the underlying type 'unsigned short'}}
    // expected-warning@-1 {{overflow in enumeration value}}
};
