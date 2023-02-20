

public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(System.in);
    PrintWriter pw = new PrintWriter(System.out);
    int tc = sc.nextInt();
    while(tc-->0){
        int n = sc.nextInt();
        int[] arr = sc.nextIntArray(n);
        int[] max = new int[n];
        max[0] = arr[0];
        int[] min = new int[n];
        min[0] = arr[0];
        for(int i = 1; i<n; i++){
            max[i] = Math.max(max[i - 1], arr[i]);
            min[i] = Math.min(min[i - 1], arr[i]);
        }
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(arr[i] != min[i] && arr[i] != max[i]){
                ans = i + 1;
                break;
            }
        }
        if(ans == -1)pw.println(ans);
        else pw.println(ans + " " + ans);
    }
    pw.flush();
}