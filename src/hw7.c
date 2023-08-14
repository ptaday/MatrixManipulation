#include "hw7.h"

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root) {

    bst_sf* node= malloc(sizeof(bst_sf));
    
    node->left_child=NULL;
    node->right_child=NULL;
    node->mat=mat;

    if(root==NULL){
     root=node;
    return root;
    }

    else
    {
      bst_sf* current=root;

      while(current!=NULL)
      {
        if(current->mat->name > node->mat->name){
           
           if(current->left_child==NULL){
           current->left_child=node;
           break;
           }

           else
            current=current->left_child;
        }

        else
        {
             
             if(current->right_child==NULL){
           current->right_child=node;
           break;
             }

            else
            current=current->right_child;
        }
      }
     

      return root;
    }
}

matrix_sf* find_bst_sf(char name, bst_sf *root) {
  
    if(root==NULL)
    return NULL;

    else
    {
        bst_sf* current=root;

        bst_sf* toBeReturned=NULL;


        while (current!=NULL)
        {
          if(current->mat->name==name){
          toBeReturned=current;
          break;
          }

           else if(current->mat->name<name)
          {
            current=current->right_child;
          }

          else
          {
            current=current->left_child;
          }
        }

        if(toBeReturned==NULL)
        return NULL;

        else
        {
            return toBeReturned->mat;
        }
    }
}

void free_bst_sf(bst_sf *root) {

   bst_sf* current=root;
   bst_sf* previous=root;

   int left=0;

   int right=0;

   while(current!=NULL)
   {
    while(current!=NULL)
    {
     if(current->left_child!=NULL)
     {
        left=1;
        right=0;
        previous=current;
       current=current->left_child;
      
     }

    else if(current->right_child!=NULL)
    {
        right=1;
        left=0;
        previous=current;
        current=current->right_child;
        
    }

    else
    {
       
        if(right==0 && left==1)
        previous->left_child=NULL;

        if(left==0&&right==1)
        previous->right_child=NULL;

        free(current->mat);
        free(current);

         

      if(current==root)
        current=NULL;

        else
        current=root;
    }
    }
   }


}

matrix_sf* add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {

    matrix_sf* new_matrix=  malloc(sizeof(matrix_sf)+mat1->num_rows*mat1->num_cols*sizeof(int));

     new_matrix->num_rows= mat1->num_rows;
     new_matrix->num_cols=mat1->num_cols;

    unsigned int i=0;

    while(i<mat1->num_rows*mat1->num_cols)
    {
     new_matrix->values[i]=mat1->values[i]+mat2->values[i];
      i++;
    }
    return new_matrix;
   
}

matrix_sf* mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2) {

  matrix_sf* new_matrix=  malloc(sizeof(matrix_sf)+mat1->num_rows*mat2->num_cols*sizeof(int));

     new_matrix->num_rows= mat1->num_rows;
     new_matrix->num_cols=mat2->num_cols;

     int a=0; int sum=0;

     for(int i=0;i<mat1->num_rows;i++)
     {
        for(int j=0;j<mat2->num_cols;j++)
        { a=0; sum=0;
            for(int k=0; k<mat2->num_rows;k++)
            {
                sum=sum+(mat1->values[(i*mat1->num_cols)+k]*mat2->values[j+a]);
                a=a+mat2->num_cols;
            }

            new_matrix->values[(i*mat2->num_cols)+j]=sum;
        }
     }

    return new_matrix;
}

matrix_sf* transpose_mat_sf(const matrix_sf *mat) {

    matrix_sf* new_matrix=  malloc(sizeof(matrix_sf)+mat->num_rows*mat->num_cols*sizeof(int));

     new_matrix->num_rows= mat->num_cols;
     new_matrix->num_cols=mat->num_rows;

     int toreplace=0;

     for(int i=0;i<mat->num_rows;i++)
     {
        for(int j=0;j<mat->num_cols;j++)
        {
           toreplace=mat->values[(i*mat->num_cols)+j];
           new_matrix->values[(j*mat->num_rows)+i]=toreplace;
        }
     }

return new_matrix;
    
}

matrix_sf* create_matrix_sf(char name, const char *expr) {
  
  int rows=0;
  int columns=0;
  char *endptr;

  int array[2];

   int count=0;

   int compute=0;


  while(count<2)
  {
     if(!isdigit(*expr))
     {
      expr=expr+1;
     }
     else
     {
       for (int i = 0; i < 2; i++) {
         array[i]= strtol(expr, &endptr, 10);
         expr = endptr + 1;
         count=count+1;

         if(count==2)
         break;
        
           
           while(!isdigit(*expr))
           expr = expr+1; // move the pointer past the space
    }
    
     }
  }

  rows=array[0];
  columns=array[1];

   matrix_sf* new_matrix=  malloc(sizeof(matrix_sf)+rows*columns*sizeof(int));

   new_matrix->name=name;
   new_matrix->num_cols=columns;
   new_matrix->num_rows=rows;

    count=0;

    int sign=1;

   while(*expr!=']')
   {
   if(*expr=='-')
    {
       sign=-1;

      expr=expr+1;
    }

     else if(!isdigit(*expr))
    expr=expr+1;

    else
    {    
        
         compute= strtol(expr, &endptr, 10);

         new_matrix->values[count]=sign*compute;

         if(sign==-1)
         sign=1;

         expr = endptr + 1;
         count=count+1;
    }
   }

return new_matrix;

}

int precedence(char c)
{
  if(c==39)
   return 3;

  else if(c=='*'||c=='/')
  return 2;

  else if(c=='+'||c=='-')
  return 1;


  else
  return 0; 

}

char* infix2postfix_sf(char *infix) {

char* postfix= malloc((strlen(infix)+1)* sizeof(char));
char* stack_of_operators=malloc((strlen(infix))*sizeof(char));

int postfix_count=0;
int stack_of_operators_count=0;


while(*infix!=NULL)
{

 
  int c=0; 
  if(isalpha(*infix))
  {
     
  postfix[postfix_count]=*infix;
  infix=infix+1;
  postfix_count=postfix_count+1;
  }

  else
  {
    
    if(*infix=='(')
    {
     stack_of_operators[stack_of_operators_count]=*infix;
     stack_of_operators_count=stack_of_operators_count+1;
      infix=infix+1;
    }

    else if(*infix==')')
    {
      while(1)
     {

    if(stack_of_operators[stack_of_operators_count-1]=='('){
      stack_of_operators[stack_of_operators_count-1]='\0';
      stack_of_operators_count=stack_of_operators_count-1;
      break;
      }

      

    postfix[postfix_count]=stack_of_operators[stack_of_operators_count-1];
    postfix_count=postfix_count+1;
    
     stack_of_operators_count=stack_of_operators_count-1;

     
      }

    infix=infix+1;
    }
    


   else if(*infix=='*'||*infix=='+'||*infix==39){

    if(stack_of_operators_count==0){
    stack_of_operators[stack_of_operators_count]=*infix;
    stack_of_operators_count=stack_of_operators_count+1;
    infix=infix+1;
    }

    else
    {
     int current_operator_precedence= precedence(*infix);

     while(stack_of_operators_count!=0)
     {
      if(current_operator_precedence>precedence(stack_of_operators[stack_of_operators_count-1]))
      {
       stack_of_operators[stack_of_operators_count]=*infix;
       stack_of_operators_count=stack_of_operators_count+1;
       infix=infix+1;
       c=1;
       break;
      }

      else
      {
        if(stack_of_operators[stack_of_operators_count-1]!='('){
        postfix[postfix_count]=stack_of_operators[stack_of_operators_count-1];
        postfix_count=postfix_count+1;

        stack_of_operators[stack_of_operators_count-1]='\0';
        stack_of_operators_count=stack_of_operators_count-1;
        }
        else
        {
          
          c=1;
          infix=infix+1;
          break;
        }
      }
     }

     if(c==0)
     {
      
      stack_of_operators[stack_of_operators_count]=*infix;
       stack_of_operators_count=stack_of_operators_count+1;
       infix=infix+1;
       c=1;
     }
    }
  }

  else
  {
    infix=infix+1;
  }

  }
}

while(stack_of_operators_count!=0)
{
  postfix[postfix_count]=stack_of_operators[stack_of_operators_count-1];
  postfix_count=postfix_count+1;
  stack_of_operators_count=stack_of_operators_count-1;
}

free(stack_of_operators);


postfix[postfix_count]='\0';

return postfix;
}

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root) {
    char* manipulated_expr=infix2postfix_sf(expr);

    char* temperory=manipulated_expr;

    matrix_sf* stack[MAX_LINE_LEN];

    int stack_count=0;

    while(*manipulated_expr!='\0')
    {

       if(isalpha(*manipulated_expr))
       {
        matrix_sf* matrix_to_be_added_on_the_stack= find_bst_sf(*manipulated_expr,root);
        stack[stack_count]=matrix_to_be_added_on_the_stack;
        manipulated_expr=manipulated_expr+1;
        stack_count=stack_count+1;
       }
       else
       {
        if(*manipulated_expr==39)
        {
         matrix_sf* first=stack[stack_count-1];
         matrix_sf* newMatrix= transpose_mat_sf(first);
         newMatrix->name='@';
      
         stack_count=stack_count-1;

         stack[stack_count]=newMatrix;
         stack_count=stack_count+1;
         manipulated_expr=manipulated_expr+1;

         if(!isalpha(first->name))
         free(first);
        }

        else if(*manipulated_expr=='*')
        {
          matrix_sf* first=stack[stack_count-1];
         matrix_sf* second=stack[stack_count-2];
        
        matrix_sf* newMatrix= mult_mats_sf(second,first);
           newMatrix->name='@';

          stack_count=stack_count-2;

          stack[stack_count]=newMatrix;
          stack_count=stack_count+1;
          manipulated_expr=manipulated_expr+1;

           if(!isalpha(first->name))
          {
            free(first);
          }

          if(!isalpha(second->name))
          {
            free(second);
          }
        }

        else
        {
         matrix_sf* first=stack[stack_count-1];
         matrix_sf* second=stack[stack_count-2];
         matrix_sf* newMatrix= add_mats_sf(second,first);
          newMatrix->name='@';
          stack_count=stack_count-2;

          stack[stack_count]=newMatrix;
          stack_count=stack_count+1;
          manipulated_expr=manipulated_expr+1;


          if(!isalpha(first->name))
          {
            free(first);
          }

          if(!isalpha(second->name))
          {
            free(second);
          }
        }
       }
    }

   matrix_sf* resultant_matrix=stack[stack_count-1];
   resultant_matrix->name=name;

    while(stack_count>0)
    {
      if(!isalpha(stack[stack_count-1]->name))
      free(stack[stack_count-1]);

      stack_count=stack_count-1;
    }

    //free(manipulated_expr);
    free(temperory);

   
   return resultant_matrix;
}

matrix_sf *execute_script_sf(char *filename) {

 char *str = NULL; 
FILE *file = fopen(filename,"r");
size_t max_line_size = 100;  

matrix_sf* stack[MAX_LINE_LEN];
int stack_count=0;

bst_sf* root=NULL;

char *secondPointer;

int count=0;
char alphabet='a';
int decider=0;
int check=0;

while(getline(&str, &max_line_size, file)!=-1)
{

  //printf("INSIDE WHILE");
  //fflush(stdout);

  count=0;check=0; decider=0;
   secondPointer=str;

   while(*secondPointer!=NULL)
   {

   // printf("INSIDE SECOND WHILE");
  //fflush(stdout);
      if(count==0&&isalpha(*secondPointer))
      {
        count=1;
        alphabet=*secondPointer;
        secondPointer=secondPointer+1;
      }

      else if(isdigit(*secondPointer))
      {
       decider=1;
       break;
      }
      else if(*secondPointer=='('||isalpha(*secondPointer))
      {
        decider=2;
        break;
      }

      else{
        secondPointer=secondPointer+1;
      }
   }

   if(decider==1)
   {

    matrix_sf* tobereturned=create_matrix_sf(alphabet,secondPointer);
    root=insert_bst_sf(tobereturned,root);
    stack[stack_count]=tobereturned;
    stack_count++;

   }

   else if(decider==2)
   {

     matrix_sf* tobereturned=evaluate_expr_sf(alphabet,secondPointer,root);
     
     root=insert_bst_sf(tobereturned,root);

    stack[stack_count]=tobereturned;
    stack_count++;
   }
}

//matrix_sf* to_be_returned=copy_matrix(stack[stack_count-1]->num_rows,stack[stack_count-1]->num_cols,stack[stack_count-1]->values);
matrix_sf* to_be_returned=malloc(sizeof(matrix_sf)+stack[stack_count-1]->num_rows*stack[stack_count-1]->num_cols*sizeof(int));
to_be_returned->name=stack[stack_count-1]->name;
to_be_returned->num_cols=stack[stack_count-1]->num_cols;
to_be_returned->num_rows=stack[stack_count-1]->num_rows;


for(int i=0;i<to_be_returned->num_cols*to_be_returned->num_rows;i++)
{
  to_be_returned->values[i]=stack[stack_count-1]->values[i];
}


//  for(int i=0;i<stack_count-1;i++)
// {
//  free(stack[i]);

//  }

free_bst_sf(root);

fclose(file);
free(str);

return to_be_returned;


}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[]) {
    matrix_sf *m = malloc(sizeof(matrix_sf)+num_rows*num_cols*sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows*num_cols*sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat) {
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows*mat->num_cols; i++) {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows*mat->num_cols-1)
            printf(" ");
    }
    printf("\n");
}

