
#line 1 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
#include "grammar.h"
#include "lexer.h"
// lemon doesn't provide prototypes for parser API, brute force include here
// and let the compiler sort it out
#include "grammar.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gc/gc.h>


#line 37 "/home/aaron/workspace/semblance/src/parser/lexer.rl"


static void print_match(const char const * type, int line, const char const * start, const char const * end) {
  printf("line %i, type %s, len: %i: '%.*s'\n", line, type, end - start, end - start, start);
}


#line 23 "/home/aaron/workspace/semblance/src/parser/lexer.c"
static const char _semblance_lexer_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	5, 1, 6, 1, 7, 2, 0, 4
	
};

static const char _semblance_lexer_cond_offsets[] = {
	0, 0, 1
};

static const char _semblance_lexer_cond_lengths[] = {
	0, 1, 0
};

static const short _semblance_lexer_cond_keys[] = {
	33, 33, 0
};

static const char _semblance_lexer_cond_spaces[] = {
	0, 0
};

static const char _semblance_lexer_key_offsets[] = {
	0, 0, 11
};

static const short _semblance_lexer_trans_keys[] = {
	10, 32, 44, 95, 545, 9, 13, 65, 
	90, 97, 122, 95, 48, 57, 65, 90, 
	97, 122, 0
};

static const char _semblance_lexer_single_lengths[] = {
	0, 5, 1
};

static const char _semblance_lexer_range_lengths[] = {
	0, 3, 3
};

static const char _semblance_lexer_index_offsets[] = {
	0, 0, 9
};

static const char _semblance_lexer_trans_targs[] = {
	1, 1, 1, 2, 1, 1, 2, 2, 
	0, 2, 2, 2, 2, 1, 1, 0
};

static const char _semblance_lexer_trans_actions[] = {
	13, 9, 7, 0, 5, 9, 0, 0, 
	0, 0, 0, 0, 0, 11, 11, 0
};

static const char _semblance_lexer_to_state_actions[] = {
	0, 1, 0
};

static const char _semblance_lexer_from_state_actions[] = {
	0, 3, 0
};

static const char _semblance_lexer_eof_trans[] = {
	0, 0, 15
};

static const int semblance_lexer_start = 1;
static const int semblance_lexer_first_final = 1;
static const int semblance_lexer_error = 0;

static const int semblance_lexer_en_main = 1;


#line 44 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

int parse(const char * const source) {
  int cs, act, lineno = 0;
  const char *ts = 0, *te = 0;

  const char * p = &source[0];
  printf("source %i chars: '%s'\n", strlen(source), source);

  void *pParser = ParseAlloc(malloc);

    
#line 109 "/home/aaron/workspace/semblance/src/parser/lexer.c"
	{
	cs = semblance_lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 55 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

  const char * pe = source + strlen(source);
  const char * eof = pe;
  
    
#line 123 "/home/aaron/workspace/semblance/src/parser/lexer.c"
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
#line 145 "/home/aaron/workspace/semblance/src/parser/lexer.c"
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
#line 14 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

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
#line 17 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{
    lineno++;
  }
	break;
	case 3:
#line 32 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;{ print_match("directive", lineno, ts, te); DIRECTIVE_START(); }}
	break;
	case 4:
#line 33 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;}
	break;
	case 5:
#line 34 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;}
	break;
	case 6:
#line 35 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p+1;}
	break;
	case 7:
#line 31 "/home/aaron/workspace/semblance/src/parser/lexer.rl"
	{te = p;p--;{ print_match("identifier", lineno, ts, te); IDENT(); }}
	break;
#line 269 "/home/aaron/workspace/semblance/src/parser/lexer.c"
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
#line 282 "/home/aaron/workspace/semblance/src/parser/lexer.c"
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

#line 60 "/home/aaron/workspace/semblance/src/parser/lexer.rl"

  int error = 0;
  if (cs == semblance_lexer_error) {
    printf("invalid character '%c'\n", ts[0]);
    error = 1;
  } else {
    Parse(pParser, 0, NULL);
  }

  ParseFree(pParser, free);

  return error;
}
