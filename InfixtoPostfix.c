#include<stdio.h>

typedef enum{lparen,rparen,plus,minus,mul,divd,mod,eos,opnd} precedence;

precedence get_token(char *s,int *n,char post[])
{
	*s = post[(*n)++];
	switch(*s)
	{
		case '(':return lparen;
		case ')':return rparen;
		case '+': return plus;
		case '-': return minus;
		case '*': return mul;
		case '/': return divd;
		case '%': return mod;
		case '\0': return eos;
		default : return opnd;
	}
}

void print_tok(precedence tok)
{
	switch(tok)
	{
		case plus: printf("+");
		break;
		case minus: printf("-");
		break;
		case mul: printf("*");
		break;
		case divd: printf("/");
		break;
		case mod: printf("%");
		break;
	}
}

void push(int ele,int *t, int stack[])
{
	stack[++(*t)]=ele;
}

precedence pop(int *t,int stack[])
{
	if (*t!=-1)
		return stack[(*t)--];
}

void postfix(char inf[])
{
	precedence token;
	char symbol;
	int stack[10],n=0,top=0;
	stack[top]=7;
	int isp[]={0,19,12,12,13,13,13,0};
	int icp[]={20,19,12,12,13,13,13,0};
	for (token=get_token(&symbol,&n,inf);token!=eos;token=get_token(&symbol,&n,inf))
	{
		if (token == opnd)
			printf("%c",symbol);
		else if (token == rparen)
		{
			while (stack[top]!=0)
				print_tok(pop(&top,stack));
			top--;
		}
		else
		{
			while (isp[stack[top]]>=icp[token])
			{
				print_tok(pop(&top,stack));
			}
			push(token,&top,stack);
		}
	}

	for (token=pop(&top,stack);token!=eos;token = pop(&top,stack))
		print_tok(token);
}

void main()
{
	char infix[20];
	printf("Input an infix expression\n");
	gets(infix);
	postfix(infix);
}
