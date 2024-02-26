import sys

def gen_djb2(max_len):
     out = ["#define stringify(s) #s"]
     out += ["#define seed 5381"]
     out += [f"#define hash{max_len}(s) (seed * 33 + stringify(s)[0])"]
     for i in range(max_len):
         out.insert(-1, f"#define hash{i}(s) (sizeof(stringify(s)) > {max_len - i} ? hash{i+1}(s) * 33 + stringify(s)[{max_len - i}] : 0)")
        #  out.insert(-1, f"#define hash{i}(s) (hash{i+1}(s) * 33 + stringify(s)[{max_len -i}]")
     print("\n".join(out))

if __name__ == "__main__":
     gen_djb2(int(sys.argv[1]))

