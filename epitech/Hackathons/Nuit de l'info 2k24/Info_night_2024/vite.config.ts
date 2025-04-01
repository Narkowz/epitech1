import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  plugins: [react()],
  base: '/Info_night_2024/',
  optimizeDeps: {
    exclude: ['lucide-react'],
  },
});
