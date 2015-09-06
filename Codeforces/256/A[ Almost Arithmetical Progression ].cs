using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace Playground
{
	public class Program
	{
		public const int
			MAXN = 4005,
			MAXV = 1000005;

		int N;
		int answer;
		int[] vals = new int[MAXN];
		List<int>[] pos = new List<int>[MAXV];
		bool[] seenAs1 = new bool[MAXV];

		int curMark;
		int[] seenAs2 = new int[MAXV];

		public void Solve ()
		{
			N = io.Next<int>();

			for (int i = 0; i < N; ++i) {
				int x = io.Next<int>();
				vals[i] = x;

				if (pos[x] == null)
					pos[x] = new List<int>();

				pos[x].Add (i);
			}			

			for (int i = 0; i < N; ++i) {
				if (!seenAs1 [vals [i]]) {

					seenAs1 [vals [i]]= true;

					answer = Math.Max(answer, 1);

					curMark++;
					for (int j = i + 1; j < N; ++j)
					{
						if (seenAs2 [vals [j]] != curMark) {

							answer = Math.Max(answer, 2);

							seenAs2 [vals [j]] = curMark;

							int cur = j;

							for (int k = 3; ; ++k)
							{
								int nextVal = (k % 2 == 0) ? vals[j] : vals[i];
								int lo = 0, hi = pos[ nextVal ].Count - 1;

								while (lo <= hi)
								{
									int mid = (lo + hi) / 2;
									if (pos[nextVal][mid] > cur)
										hi = mid - 1;
									else
										lo = mid + 1;
								}

								int nextPos = hi + 1;

								if (nextPos >= pos[ nextVal ].Count)
								    break;

								cur = pos[nextVal][nextPos];

							    answer = Math.Max(answer, k);
							}							
						}					
					}
				}
			}

			io.PrintLine (answer);

		}

        #region Program	

        private readonly MyIo io;

        public Program(MyIo io)
        {
            this.io = io;
        }

        public static void Main(string[] args)
        {
            using (MyIo io = new MyIo())
            {
                new Program(io).Solve();
            }
        }

        #endregion
    }

    #region MyIo

    public class MyIo : IDisposable
    {
        private readonly TextReader inputStream;
        private readonly TextWriter outputStream = Console.Out;

        private string[] tokens;
        private int pointer;

        public MyIo()
            : this(System.Console.In)
        {
        }

        public MyIo(TextReader inputStream)
        {
            this.inputStream = inputStream;
        }

        public string NextLine()
        {
            try
            {
                return inputStream.ReadLine();
            }
            catch (IOException)
            {
                return null;
            }
        }

        public string NextString()
        {
            try
            {
                while (tokens == null || pointer >= tokens.Length)
                {
                    tokens = NextLine().Split(new char[] { &#39; &#39;, &#39;\t&#39; }, StringSplitOptions.RemoveEmptyEntries);
                    pointer = 0;
                }
                return tokens[pointer++];
            }
            catch (IOException)
            {
                return null;
            }
        }

        public T Next<T>()
        {
            return (T)Convert.ChangeType(NextString(), typeof(T));
        }


        public IEnumerable<T> NextSeq<T>(int n)
        {
            for (int i = 0; i < n; i++)
                yield return Next<T>();
        }

        public void Print(string format, params object[] args)
        {
            outputStream.Write(string.Format(CultureInfo.InvariantCulture, format, args));
        }

        public void PrintLine(string format, params object[] args)
        {
            Print(format, args);
            outputStream.WriteLine();
        }

        public void Print<T>(T o)
        {
            outputStream.Write(o);
        }

        public void PrintLine<T>(T o)
        {
            outputStream.WriteLine(o);
        }

        public void Close()
        {
            inputStream.Close();
            outputStream.Close();
        }

        void IDisposable.Dispose()
        {
            Close();
        }
    }

    #endregion
}

