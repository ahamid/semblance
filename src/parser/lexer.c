
#line 1 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
#include "grammar.h"
#include "lexer.h"
#include "parser.h"
// lemon doesn't provide prototypes for parser API, brute force include here
// and let the compiler sort it out
#include "grammar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gc/gc.h>


#line 42 "/home/aaron/workspace/semblance/src/parser/lexer.rl"


#define PRINT_MATCH(T) print_match(T, lineno, ts, te)

static void print_match(const char const * type, int line, const char const * start, const char const * end) {
  printf("line %i, type %s, len: %i: '%.*s'\n", line, type, end - start, end - start, start);
}


#line 26 "/home/aaron/workspace/semblance/src/parser/lexer.c"
static const char _semblance_lexer_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 7, 1, 
	8, 1, 9, 1, 10, 1, 11, 2, 
	5, 0
};

static const char _semblance_lexer_cond_offsets[] = {
	0, 0, 0, 0, 0, 1, 1, 1, 
	1, 1
};

static const char _semblance_lexer_cond_lengths[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0
};

static const short _semblance_lexer_cond_keys[] = {
	33, 33, 0
};

static const char _semblance_lexer_cond_spaces[] = {
	0, 0
};

static const char _semblance_lexer_key_offsets[] = {
	0, 0, 2, 4, 10, 25, 28, 30, 
	34, 40
};

static const short _semblance_lexer_trans_keys[] = {
	48, 57, 48, 57, 48, 57, 65, 70, 
	97, 102, 10, 32, 44, 45, 48, 95, 
	545, 9, 13, 49, 57, 65, 90, 97, 
	122, 46, 48, 57, 48, 57, 46, 120, 
	48, 57, 48, 57, 65, 70, 97, 102, 
	95, 48, 57, 65, 90, 97, 122, 0
};

static const char _semblance_lexer_single_lengths[] = {
	0, 0, 0, 0, 7, 1, 0, 2, 
	0, 1
};

static const char _semblance_lexer_range_lengths[] = {
	0, 1, 1, 3, 4, 1, 1, 1, 
	3, 3
};

static const char _semblance_lexer_index_offsets[] = {
	0, 0, 2, 4, 8, 20, 23, 25, 
	29, 33
};

static const char _semblance_lexer_indicies[] = {
	0, 1, 3, 2, 4, 4, 4, 2, 
	6, 5, 7, 8, 9, 10, 11, 5, 
	0, 10, 10, 1, 13, 0, 12, 3, 
	14, 13, 15, 0, 12, 4, 4, 4, 
	16, 10, 10, 10, 10, 17, 0
};

static const char _semblance_lexer_trans_targs[] = {
	5, 0, 4, 6, 8, 4, 4, 4, 
	1, 7, 9, 4, 4, 2, 4, 3, 
	4, 4
};

static const char _semblance_lexer_trans_actions[] = {
	5, 0, 21, 0, 0, 9, 23, 11, 
	0, 5, 0, 7, 15, 0, 17, 0, 
	19, 13
};

static const char _semblance_lexer_to_state_actions[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0
};

static const char _semblance_lexer_from_state_actions[] = {
	0, 0, 0, 0, 3, 0, 0, 0, 
	0, 0
};

static const char _semblance_lexer_eof_trans[] = {
	0, 0, 3, 3, 0, 13, 15, 13, 
	17, 18
};

static const int semblance_lexer_start = 4;
static const int semblance_lexer_first_final = 4;
static const int semblance_lexer_error = 0;

static const int semblance_lexer_en_main = 4;


#line 51 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

int parse(const char * const source, const ParserCallbacks * const callbacks) {
  int cs, act, lineno = 0;
  const char *ts = 0, *te = 0;

  const char * p = &source[0];
  printf("source %i chars: '%s'\n", strlen(source), source);

  void *pParser = ParseAlloc(malloc);

    
#line 135 "/home/aaron/workspace/semblance/src/parser/lexer.c"
	{
	cs = semblance_lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 62 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

  const char * pe = source + strlen(source);
  const char * eof = pe;
  
    
#line 149 "/home/aaron/workspace/semblance/src/parser/lexer.c"
	{
	int _klen;
	unsigned int _trans;
	short _widec;
	const char *_acts;
	unsigned int _nacts;
	const short *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _semblance_lexer_actions + _semblance_lexer_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "NONE"
	{ts = p;}
	break;
#line 171 "/home/aaron/workspace/semblance/src/parser/lexer.c"
		}
	}

	_widec = (*p);
	_klen = _semblance_lexer_cond_lengths[cs];
	_keys = _semblance_lexer_cond_keys + (_semblance_lexer_cond_offsets[cs]*2);
	if ( _klen > 0 ) {
		const short *_lower = _keys;
		const short *_mid;
		const short *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( _widec < _mid[0] )
				_upper = _mid - 2;
			else if ( _widec > _mid[1] )
				_lower = _mid + 2;
			else {
				switch ( _semblance_lexer_cond_spaces[_semblance_lexer_cond_offsets[cs] + ((_mid - _keys)>>1)] ) {
	case 0: {
		_widec = (short)(128 + ((*p) - -128));
		if ( 
#line 15 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

    ts == source || (*(ts - 1) == '\n')
   ) _widec += 256;
		break;
	}
				}
				break;
			}
		}
	}

	_keys = _semblance_lexer_trans_keys + _semblance_lexer_key_offsets[cs];
	_trans = _semblance_lexer_index_offsets[cs];

	_klen = _semblance_lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const short *_lower = _keys;
		const short *_mid;
		const short *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( _widec < *_mid )
				_upper = _mid - 1;
			else if ( _widec > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _semblance_lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const short *_lower = _keys;
		const short *_mid;
		const short *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( _widec < _mid[0] )
				_upper = _mid - 2;
			else if ( _widec > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _semblance_lexer_indicies[_trans];
_eof_trans:
	cs = _semblance_lexer_trans_targs[_trans];

	if ( _semblance_lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _semblance_lexer_actions + _semblance_lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 18 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{
    lineno++;
    EMIT(EOL);
  }
	break;
	case 3:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 4:
#line 32 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;{ PRINT_MATCH("directive_start"); EMIT(DIRECTIVE_START); }}
	break;
	case 5:
#line 34 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;}
	break;
	case 6:
#line 36 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;{ PRINT_MATCH("COMMA"); EMIT(COMMA); }}
	break;
	case 7:
#line 33 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p;p--;{ PRINT_MATCH("identifier"); EMIT(IDENT); }}
	break;
	case 8:
#line 37 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p;p--;{ EMIT(INT); }}
	break;
	case 9:
#line 38 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p;p--;{ EMIT(FLOAT); }}
	break;
	case 10:
#line 39 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p;p--;{ EMIT(HEX); }}
	break;
	case 11:
#line 37 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{{p = ((te))-1;}{ EMIT(INT); }}
	break;
#line 313 "/home/aaron/workspace/semblance/src/parser/lexer.c"
		}
	}

_again:
	_acts = _semblance_lexer_actions + _semblance_lexer_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 326 "/home/aaron/workspace/semblance/src/parser/lexer.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _semblance_lexer_eof_trans[cs] > 0 ) {
		_trans = _semblance_lexer_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 67 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

  int error = 0;
  if (cs == semblance_lexer_error) {
    printf("invalid character '%c'\n", ts[0]);
    error = 1;
  } else {
    printf("emitting synthetic eol\n");
    EMIT_BLANK(EOL);
    printf("final parse\n");
    Parse(pParser, 0, NULL, callbacks);
  }

  ParseFree(pParser, free);

  return error;
}
