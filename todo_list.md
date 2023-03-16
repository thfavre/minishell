# === TODO ===
- \>>
- <<
- &&
- comamnd au path relatif et absolu
- syntax erors

# === $ Bug ===

- if $xxx < xxx not found need to have skip and pass to next
- if $xxx$HOME < xxx not found need to still get $HOME
- fix $ with special char -> "+=-^%$#@![]{},./?\|" and all numbers
- line 60 ft\_add\_varenv\_in\_token.c need to free a variable


# === Trim quote ===

- need rework if $a is in a venv or not
- ""$HOME'"'"'"	after expand -> ""/Users/mjulliat[']"'"'" [']\<missing
- "'$a'" 		after expand -> "'ls -la[']" ["]<missing


# === Syntax Error Bug ===

- > with no file should return syntax error
- parentheses not close should return syntax error
- quote and single quote not close should return syntax error

# === Bug redirection ===

## Crashes :
	>
	<
	>test
	<test
