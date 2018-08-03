class dsu {

    public :
        int n , max_component;
        vector<int> P , R , S;
        dsu(int n){
            this->n = n ;
            P.resize(n+1) ;
            R.resize(n+1) ;
            S.resize(n+1) ;
            for(int i=1;i<=n;i++){
                R[i] = 0 ;
                P[i] = i ;
                S[i] = 1 ;
            }
            max_component = 1 ;
        }

        int find(int x){
            if(x != P[x]){
                P[x] = find(P[x]) ;
            }
            return P[x] ;
        }

        bool add_edge(int x,int y){
            int rx , ry ;
            rx = find(x) ;
            ry = find(y) ;
            if(rx != ry){
                if(R[rx] < R[ry]){
                    P[rx] = ry ;
                    S[ry] += S[rx] ;
                    max_component = max(max_component,S[ry]) ;
                }else{
                    P[ry] = rx ;
                    S[rx] += S[ry] ;
                    max_component = max(max_component,S[rx]) ;
                }
                if(R[rx] == R[ry]){
                    R[rx] ++ ;
                }
                return true ;
            }
            return false ;
        }

};