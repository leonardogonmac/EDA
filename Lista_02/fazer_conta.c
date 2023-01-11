int faz_conta_direito(int parcelas, char op){
    int num1;
    int num_after;
    int sum_after = 0;

    for(int i = 0; i < parcelas; i++){
        if(i == 0){
            scanf("%d", &num1);
        }
        else{
            scanf("%d", &num_after);
            sum_after += num_after;
        }
    }
    
    if(op == '-'){
        num1 = num1 -sum_after;
    }
    else if(op == '+'){
        num1 += sum_after;
    }

    return num1;
}
