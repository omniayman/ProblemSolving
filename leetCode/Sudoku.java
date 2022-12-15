class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++)
            { if(board[i][j]!='.'){
                for(int k=i+1;k<9;k++) {

                    if(board[i][j]==board[k][j])
                    
                        return false;
                }
                for(int k=j+1;k<9;k++) {

                    if(board[i][j]==board[i][k])
                    
                        return false;
                }
              
                    if((i+1)%3==1) {
                   if((j+1)%3==1)
                    {if(board[i][j]==board[i+1][j+1]||board[i][j]==board[i+1][j+2]||board[i][j]==board[i+2][j+1]||board[i][j]==board[i+2][j+2])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==2)
                    {if(board[i][j]==board[i+1][j-1]||board[i][j]==board[i+2][j-1]||board[i][j]==board[i+1][j+1]||board[i][j]==board[i+2][j+1])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==0)
                    
                    {
                        
                        if(board[i][j]==board[i+1][j-1]||board[i][j]==board[i+2][j-1]||board[i][j]==board[i+1][j-2]||board[i][j]==board[i+2][j-2])
                    
                        return false;
                    
                    }
                    }

                      else if((i+1)%3==2) {
                   if((j+1)%3==1)
                    {if(board[i][j]==board[i-1][j+1]||board[i][j]==board[i+1][j+1]||board[i][j]==board[i+1][j+2]||board[i][j]==board[i-1][j+2])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==2)
                    {if(board[i][j]==board[i-1][j-1]||board[i][j]==board[i-1][j+1]||board[i][j]==board[i+1][j-1]||board[i][j]==board[i+1][j+1])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==0)
                    {if(board[i][j]==board[i-1][j-1]||board[i][j]==board[i-1][j-2]||board[i][j]==board[i+1][j-1]||board[i][j]==board[i+1][j-2])
                    
                        return false;
                    
                    }
                    }
                    else if((i+1)%3==0) {
                   if((j+1)%3==1)
                    {if(board[i][j]==board[i-1][j+1]||board[i][j]==board[i-2][j+1]||board[i][j]==board[i-1][j+2]||board[i][j]==board[i-2][j+2])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==2)
                    {if(board[i][j]==board[i-2][j-1]||board[i][j]==board[i-1][j-1]||board[i][j]==board[i-1][j+1]||board[i][j]==board[i-2][j+1])
                    
                        return false;
                    
                    }
                    else if((j+1)%3==0)
                    {if(board[i][j]==board[i-1][j-1]||board[i][j]==board[i-2][j-1]||board[i][j]==board[i-1][j-2]||board[i][j]==board[i-2][j-2])
                    
                        return false;
                    
                    }
                    }
                    
                }

            }
        }
        return true;
    }
}
